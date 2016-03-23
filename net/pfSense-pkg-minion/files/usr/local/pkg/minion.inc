<?php
/*
	minion.inc
*/
require_once('config.inc');
require_once('interfaces.inc');
require_once('service-utils.inc');
require_once('util.inc');

define('MINION_BASE', '/opt/minion');

function minion_write_rcfile() {
        global $config;
        if (isset($config['installedpackages']['minion']['config'][0])) {
                $minion_config = $config['installedpackages']['minion']['config'][0];
        } else {
                $minion_config = array();
        }

        $start = "if [ ! -d /dev/fd ]; then\n";
        $start .= "     /sbin/mount -t fdescfs fdesc /dev/fd\n";
        $start .= "fi\n";
        $start .= "if [ ! -d /proc/0 ]; then\n";
        $start .= "     /bin/mkdir -p /proc\n";
        $start .= "     /sbin/mount -t procfs procfs /proc\n";
        $start .= "fi\n";
        $start .= "export JAVA_HOME=/usr/local/openjdk8\n";
        $start .= MINION_BASE . "/bin/start\n";

        $stop = MINION_BASE . "/bin/stop\n";

        write_rcfile(array(
                "file" => "minion-daemon.sh",
                "start" => $start,
                "stop" => $stop
                )
        );
}

function minion_sync() {
        global $config;
        conf_mount_rw();

        if (is_service_running("minion")) {
                stop_service("minion");
        }

        // Is package enabled?
        if ($config['installedpackages']['minion']['config'][0]['enable']) {
                minion_write_rcfile();
                start_service("minion");
        } else {
                unlink_if_exists("/usr/local/etc/rc.d/minion-daemon.sh");
        }

        conf_mount_ro();
}
?>

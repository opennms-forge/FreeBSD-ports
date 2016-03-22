<?php
/*
	minion.priv.inc
*/
global $priv_list;

$priv_list['page-service-minion'] = array();
$priv_list['page-service-minion']['name'] = "WebCfg - Services: Minion package";
$priv_list['page-service-minion']['descr'] = "Allow access to Minion package GUI";
$priv_list['page-service-minion']['match'] = array();
$priv_list['page-service-minion']['match'][] = "pkg_edit.php?xml=minion.xml*";

?>

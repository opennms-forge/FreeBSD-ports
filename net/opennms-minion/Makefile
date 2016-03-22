# $FreeBSD$

PORTNAME=	opennms-minion
PORTVERSION=	${OPENNMS_MAJOR_VERSION}.${OPENNMS_MINOR_VERSION}.${OPENNMS_INC_VERSION}.${OPENNMS_DATE_VERSION}
PORTREVISION=	0
CATEGORIES=	net java

MASTER_SITES=	http://yum.opennms.org/branches/release-19.0.0/common/opennms/:source1
DISTFILES+=	opennms-minion-container-${OPENNMS_PACKAGE_VERSION}.noarch.rpm:source1 \
		opennms-minion-features-core-${OPENNMS_PACKAGE_VERSION}.noarch.rpm:source1 \
		opennms-minion-features-default-${OPENNMS_PACKAGE_VERSION}.noarch.rpm:source1
EXTRACT_ONLY=	opennms-minion-container-${OPENNMS_PACKAGE_VERSION}.noarch.rpm \
                opennms-minion-features-core-${OPENNMS_PACKAGE_VERSION}.noarch.rpm \
                opennms-minion-features-default-${OPENNMS_PACKAGE_VERSION}.noarch.rpm

MAINTAINER=	jesse@opennms.org
COMMENT?=	OpenNMS Minion ${OPENNMS_MAJOR_VERSION}

LICENSE=	AGPLv3

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPENNMS_MAJOR_VERSION=  19
OPENNMS_MINOR_VERSION=  0
OPENNMS_INC_VERSION=    0
OPENNMS_DATE_VERSION=	2016.10.13

OPENNMS_PACKAGE_VERSION=	19.0.0-0.20161124.onms1150.release.19.0.0.3

USES=           perl5
USE_JAVA=       yes
JAVA_OS=        native
JAVA_VERSION=   1.8
JAVA_VENDOR=    openjdk
JAVA_RUN=       yes

RUN_DEPENDS+=   bash:${PORTSDIR}/shells/bash

USERS=		minion
GROUPS=		minion

MINIONOWN=      minion
MINIONGRP=      minion

INSTPREFIX= 	${PREFIX}/minion

NO_BUILD=	yes

do-install:
		${MKDIR} ${STAGEDIR}${INSTPREFIX}
		(cd ${WRKDIR}/opt/minion && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTPREFIX})
		(cd ${WRKDIR}/opt/minion/bin && ${COPYTREE_BIN} . ${STAGEDIR}${INSTPREFIX}/bin)
		@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s minion -not -type d) >> ${TMPPLIST}

.include <bsd.port.mk>

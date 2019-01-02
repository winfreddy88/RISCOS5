# Copyright 2000 Pace Micro Technology plc
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Makefile for Network Fetcher common
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 04-May-00  SNB    Created
#

#
# Component specific options:
#

LIBDIR = <Lib$Dir>.Fetchers

TARGET = FetchLibZM
OBJS   = o.base64 o.dns o.generic o.URLclient
DIRS   = o._dirs


CINCLUDES = -ITCPIPLibs: -IC:
CFLAGS    = -Wp -zm -zps1

include Makefiles:StdTools
include Makefiles:StdRules

export: export_${PHASE}
        @|

export_hdrs:
        ${MKDIR} ${LIBDIR}.h
        ${CP} FetchMake ${LIBDIR}.FetchMake ${CPFLAGS}
        ${CP} h.* ${LIBDIR}.h.* ${CPFLAGS}
        ${CP} VersionNum ${LIBDIR}.LibVersion ${CPFLAGS}
        @echo ${COMPONENT}: header export complete

export_libs: ${TARGET} ${DIRS}
        ${MKDIR} ${LIBDIR}.o
        ${CP} ${TARGET} ${LIBDIR}.o.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: library export complete

clean:
        ${XWIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @echo ${COMPONENT}: cleaned

${TARGET}: ${OBJS}
        ${AR} ${ARFLAGS} $@ ${OBJS}

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

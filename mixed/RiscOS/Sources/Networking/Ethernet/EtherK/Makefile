# Copyright 2002 Tematic Ltd
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
# Makefile for EtherK
#

COMPONENT   = EtherK
TARGET     ?= EtherK
OBJS        = em_asm em_riscos if_em if_em_hw msgs \
              info log mbuf generic filter test ekmodule
CMHGFILE    = EKHdr
CMHGDEPENDS = ekmodule msgs
ROMCDEFINES = -DROM
RES_AREA    = messages_file
CUSTOMSA    = custom
HDRS        =
CINCLUDES   = -ITCPIPLibs:,C:

include CModule

#
# Description of extra compilation options:
# DBG_STATS  Gather extra driver statistics for debugging such as the time
#            used in the IRQ handler and the transmit routine.
#
DFLAGS      = -DRISCOS -DDBG=0 -DINET -DKERNEL
CFLAGS     += ${DFLAGS} ${OPTIONS} -Wp 
CDFLAGS    += -fn -DDEBUGLIB
LIBS       += ${ASMUTILS} ${CALLXLIB} ${INETLIB} ${UNIXLIB}
DBG_LIBS   += ${SOCK5LIB}

#
# Specials for install (and standalone because they use the same override)
#
standalone: rm.${SA_TARGET}
        @${ECHO} ${COMPONENT}: ram module built

install: install_${TARGET}; @

install_EtherK: rm.${SA_TARGET}
        ${MKDIR} ${INSTDIR}
        ${CP} rm.${SA_TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: ram module installed

install_AutoSense: AutoSense.${COMPONENT}
        ${CP} AutoSense.${COMPONENT} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: AutoSense file installed

# Dynamic dependencies:

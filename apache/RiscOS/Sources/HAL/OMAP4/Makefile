# Copyright 2011 Castle Technology Ltd
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
# Makefile for OMAP-4 HAL
#

COMPONENT = OMAP-4 HAL
TARGET = OMAP4
OBJS = Top Boot Interrupts Timers CLib CLibAsm UART Debug PRCM Video USB I2C RTC SDMA TPS Audio GPIO GPMC NVMemory KbdScan SDIO SR44x PowerCtrl PL310 DBell

HDRS =
CMHGFILE =
CUSTOMRES = custom
CUSTOMROM = custom
ROM_TARGET = custom
LNK_TARGET = custom
AIFDBG    = aif._${TARGET}
GPADBG    = gpa.GPA

include CModule

CCFLAGS += -ff -APCS 3/32bit/nofp/noswst
ASFLAGS += -APCS 3/nofp/noswst

resources:
        @${ECHO} ${COMPONENT}: no resources

rom: aof.${TARGET}
        @${ECHO} ${COMPONENT}: rom module built

_debug: ${GPADBG}
        @echo ${COMPONENT}: debug image built

install_rom: linked.${TARGET}
        ${CP} linked.${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: rom module installed

aof.${TARGET}: ${ROM_OBJS_} ${ROM_LIBS} ${DIRS} ${ROM_DEPEND}
        ${LD} -o $@ -aof ${ROM_OBJS_} ${ROM_LIBS}

linked.${TARGET}: aof.${TARGET}
        ${LD} ${LDFLAGS} ${LDLINKFLAGS} -o $@ -bin -base 0xFC000000 aof.${TARGET}

${AIFDBG}: ${ROM_OBJS_} ${ROM_LIBS}
        ${MKDIR} aif
        ${LD} -aif -bin -d -o ${AIFDBG} ${ROM_OBJS_} ${ROM_LIBS}

${GPADBG}: ${AIFDBG}
        ToGPA -s ${AIFDBG} ${GPADBG}

# Dynamic dependencies:

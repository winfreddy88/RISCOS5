# Copyright 2017 Castle Technology Ltd
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
# Makefile for iMx6 HAL
#

VideoInHAL ?= FALSE

COMPONENT = iMx6_HAL
TARGET = iMx6
OBJS = Top Boot Interrupts Timers CLib CLibAsm UART Debug PRCM Video I2C RTC SDMA TPS Audio GPIO NVMemory KbdScan SATA EtherDrv USB iMx6qboard SDIO SPI watchdog CPUSpeed PL310 DBell #hdmi_common  hdmi_tx ipu_idmac ipu_common board_hdmi #hdmi_test #CPUClk  hdmi_tx_phy   ips_disp_panel ips_display ipu_image ccm_pll    enet_test  enet_drv  ipu_di hdmi_tx_audio hdmi_print hdmi_audio ipu_dc ipu_dp ipu_dmfc

HDRS =
ASMHDRS =
CMHGFILE =
CUSTOMRES = custom
CUSTOMROM = custom
ROM_TARGET = custom
LNK_TARGET = custom
AIFDBG    = aif._iMx6
GPADBG    = gpa.GPA

ifeq (${VideoInHAL},TRUE)
# hdmi_print
OBJS += hdmi_tx_audio  hdmi_audio ipu_dc ipu_dp ipu_dmfc
CFLAGS += -DVideoInHAL
endif
ASFLAGS += -PD "VideoInHAL SETL {${VideoInHAL}}"

include StdTools
include CModule


# -ec flag ignores error due to mismatched pointer types
# cflags, not ccflags, is used in stdtools etc      -ec
#CFLAGS += -c++ -ff -APCS 3/32bit/nofp
CFLAGS +=  -ff -APCS 3/32bit/nofp/noswst
#CCFLAGS += -ff -ec -APCS 3/32bit/nofp/noswst
ASFLAGS += -APCS 3/nofp/noswst --cpu 7-A.security
AASMFLAGS += -APCS 3/nofp/noswst


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

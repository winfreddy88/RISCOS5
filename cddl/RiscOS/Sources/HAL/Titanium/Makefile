#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "Licence").
# You may not use this file except in compliance with the Licence.
#
# You can obtain a copy of the licence at
# cddl/RiscOS/Sources/HAL/Titanium/LICENCE.
# See the Licence for the specific language governing permissions
# and limitations under the Licence.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the Licence file. If applicable, add the
# following below this CDDL HEADER, with the fields enclosed by
# brackets "[]" replaced with your own identifying information:
# Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
#
# Copyright 2014 Elesar Ltd.  All rights reserved.
# Use is subject to license terms.
#
# Makefile for Titanium HAL
#

COMPONENT  = Titanium HAL
TARGET     = Titanium
OBJS       = Top Entries Init Timers IIC Interrupts KbdScan Muxing \
             NVMemory USB Utils Video Counter SDHCI EtherNIC Miscellaneous \
             RTC PCI PCIProbing PMIC SATA UART GPIO Audio CPUClk SDMA
HDRS       =
CMHGFILE   =
CUSTOMRES  = custom
CUSTOMROM  = custom
ROM_TARGET = custom
LNK_TARGET = custom

include CModule

CFLAGS    += -ff -APCS 3/32bit/nofp/noswst -DPCI_SWITCHES=0
ASFLAGS   += -APCS 3/nofp/noswst -PD "Vayu SETL {FALSE}"

rom: aof.${TARGET}
        @${ECHO} ${COMPONENT}: rom module built

install_rom: linked.${TARGET}
        ${CP} linked.${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: rom module installed

aof.${TARGET}: ${ROM_OBJS_} ${ROM_LIBS} ${DIRS} ${ROM_DEPEND}
        ${LD} -o $@ -aof ${ROM_OBJS_} ${ROM_LIBS}

linked.${TARGET}: aof.${TARGET}
        ${LD} ${LDFLAGS} ${LDLINKFLAGS} -o $@ -bin -base 0xFC000000 aof.${TARGET}

# Dynamic dependencies:

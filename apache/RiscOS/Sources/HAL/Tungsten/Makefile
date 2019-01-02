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
# Makefile for Tungsten HAL
#

include StdTools

CFLAGS  = -c ${THROWBACK} -Wc -ff -cpu 5TE -APCS 3/32bit/noswst -depend !Depend -IC:,TCPIPLibs:,C:USB
ASFLAGS = -depend !Depend -g -APCS 3/nofp/noswst -cpu 5TE ${THROWBACK}
COMPONENT = Tungsten
TARGET    = bin.Tungsten
DBGTARGET = aif.Tungsten
GPATARGET = gpa.Tungsten
EXPORTS   = 

OBJECTS   = o.Top o.Boot o.IIC o.Interrupts o.Timers o.NVMemory o.MachineID \
            o.PCIasm o.DebugPCI o.Video o.PCI o.CLib o.CLibAsm o.ATA \
            o.M1535DMA o.KbdScan o.UART o.Audio o.MSI o.RTC o.PCItung

DIRS      = dirs

.s.o:;  ${AS} ${ASFLAGS} $< $@
.c.o:;  ${CC} ${CFLAGS} $< $@

#
# Generic rules:
#
rom: ${TARGET} ${DIRS}
        @echo ${COMPONENT}: rom module built

debug: ${GPATARGET} ${DIRS}
        @echo ${COMPONENT}: debug module built

install_rom: ${TARGET} ${DIRS}
        ${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: rom module installed

clean:
        ${RM} ROM
        ${RM} ${TARGET}
        ${XWIPE} o   ${WFLAGS}
        ${XWIPE} aif ${WFLAGS}
        ${XWIPE} bin ${WFLAGS}
        ${XWIPE} gpa ${WFLAGS}
        @echo ${COMPONENT}: cleaned

export: ${EXPORTS}
        @echo ${COMPONENT}: export complete

resources:
        @echo ${COMPONENT}: no resources

${TARGET}: ${OBJECTS}
        ${LD} -bin -base 0xFC000000 -o $@ ${OBJECTS}

${DBGTARGET}: ${OBJECTS}
        ${LD} -bin -aif -d -o $@ ${OBJECTS}

${GPATARGET}: ${DBGTARGET}
        ${TOGPA} -s ${DBGTARGET} $@

dirs:
        ${MKDIR} aif
        ${MKDIR} bin
        ${MKDIR} gpa
        ${MKDIR} o

# Dynamic dependencies:

# Copyright 2005 Castle Technology Ltd
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
# Makefile for PsionNB2 HAL
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 25-May-94  AMcC         Created.
#

#
# Paths
#
EXP_HDR = <export$dir>
C_EXP_HDR = <cexport$dir>.Global.h

#
# Generic options:
#
MKDIR   = mkdir -p
AS      = aasm
ARMASM  = objasm
CC      = cc
CP      = copy
RM      = remove
CCFLAGS = -c ${THROWBACK} -Wc -ff -cpu 5TE -APCS 3/32bit/noswst -depend !Depend -IC:,TCPIPLibs:,C:USB
ASFLAGS = -depend !Depend ${THROWBACK} ${REVB} -Stamp -quit -To $@ -From
ARMASMFLAGS = -depend !Depend ${REVB} ${THROWBACK} -g -APCS 3/nofp/noswst -cpu 5TE 
CPFLAGS = ~cfr~v

TOKENISE = tokenise
TOKENS   = Hdr:Tokens

#
# Program specific options:
#
COMPONENT = PsionNB2
TARGET    = bin.PsionNB2
DBGTARGET = aif.PsionNB2
GPATARGET = gpa.PsionNB2
EXPORTS   = 

OBJECTS   = o.Top o.Boot o.IIC o.Interrupts o.Timers o.NVMemory o.MachineID \
            o.Video o.CLib o.CLibAsm o.PCIasm \
            o.USBHAL o.UART o.Audio o.USBPsionNB2 o.Debug
# o.PCIasm  o.DebugPCI  o.ATA
DIRS      = dirs

.s.o:;  ${ARMASM} ${ARMASMFLAGS} $< $@
.c.o:;  ${CC} ${CCFLAGS} $< $@

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
        -Wipe o ~C~V
        -Wipe aif ~C~V
        -Wipe bin ~C~V
        -Wipe gpa ~C~V
        @echo ${COMPONENT}: cleaned

export: ${EXPORTS}
        @echo ${COMPONENT}: export complete

resources:
        @echo ${COMPONENT}: no resources

${TARGET}: ${OBJECTS}
        Link -bin -base 0xFC000000 -o $@ ${OBJECTS}

${DBGTARGET}: ${OBJECTS}
        Link -bin -aif -d -o $@ ${OBJECTS}

${GPATARGET}: ${DBGTARGET}
        ToGPA -s ${DBGTARGET} $@

dirs:
        ${MKDIR} aif
        ${MKDIR} bin
        ${MKDIR} gpa
        ${MKDIR} o

# Dynamic dependencies:

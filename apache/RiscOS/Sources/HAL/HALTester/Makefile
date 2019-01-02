# Copyright 2009 Castle Technology Ltd
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
# Makefile for HALTester
#

include StdTools

CCFLAGS = -c ${THROWBACK} -Wc -ff -cpu 5TE -APCS 3/32bit/noswst -depend !Depend -IC:,TCPIPLibs:,C:USB
ASFLAGS = -depend !Depend -g -APCS 3/nofp/noswst ${THROWBACK} -cpu 5TE

#
# Program specific options:
#
COMPONENT = HALTester
TARGET    = rm.Kernel
DIRS      = o.dirs
OBJECTS   = o.Kernel o.CLib o.main o.CLibAsm o.HALCalls

#
# Generic rules:
#
.SUFFIXES: .o .s
.s.o:; ${AS} ${ASFLAGS} -o $@ $<
.c.o:; ${CC} ${CCFLAGS} $< $@

rom: ${TARGET} ${DIRS}
     @${ECHO} ${COMPONENT}: rom module built

install_rom: ${TARGET}
        ${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: rom module installed

${DIRS}:
        ${MKDIR} o
        ${MKDIR} rm
        ${TOUCH} $@

clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} rm ${WFLAGS}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJECTS}
        ${LD} -bin -o ${TARGET} ${OBJECTS}

# Dynamic dependencies:

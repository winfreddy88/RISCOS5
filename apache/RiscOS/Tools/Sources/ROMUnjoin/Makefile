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
# Project:   ROMUnjoin

#
# Generic options:
#
MKDIR   = cdir
AS      = objasm
CC      = cc
CMHG    = cmhg
CP      = copy
LD      = link
RM      = remove
WIPE    = x wipe
STRIP   = stripdepnd

AFLAGS  = -depend !Depend -Stamp -quit
CFLAGS  = -c -depend !Depend ${INCLUDES} ${DFLAGS}
CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

#
# Libraries
#
CLIB      = CLIB:o.stubs
RLIB      = RISCOSLIB:o.risc_oslib
RSTUBS    = RISCOSLIB:o.rstubs
ROMSTUBS  = RISCOSLIB:o.romstubs
ROMCSTUBS = RISCOSLIB:o.romcstubs
ABSSYM    = RISC_OSLib:o.AbsSym
WRAPPER   = s.ModuleWrap

#
# Rule patterns
#
.c.o:;      ${CC} ${CFLAGS} -o $@ $<
.s.o:;      ${AS} ${AFLAGS} $< $@

#
# Include files
#
INCLUDES = -IC:

#
# Program specific options:
#
COMPONENT   = ROMUnjoin
APPLICATION = ROMUnjoin
TARGET      = ROMUnjoin
OBJS = o.ROMUnjoin

#
# Build for application:
#
ROMUnjoin:	${OBJS} ${CLIB} dirs
		${LD} -o $@ ${OBJS} ${CLIB}

dirs:
        ${MKDIR} o

#
# build an application:
#
all:	${APPLICATION}
	@echo ${APPLICATION} built

install: ${TARGET}
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@echo ${COMPONENT}: tool installed in library

clean:
        ${RM} ${TARGET}
        ${WIPE} ${OBJS} ${WFLAGS}
        ${WIPE} o ${WFLAGS}
        ${STRIP}

# Dynamic dependencies:

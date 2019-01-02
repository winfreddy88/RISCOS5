# Copyright 1997 Acorn Computers Ltd
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
# Makefile for KeyWatch
#

#
# Paths
#
EXP_HDR = <Cexport$dir>

#
# Generic options:
#
MKDIR   = cdir
AS      = objasm
CC      = cc
CMHG    = cmhg
CP      = copy
LD      = link
REMOVE  = remove
WIPE    = x wipe
STRIP   = stripdepnd

AFLAGS = -depend !Depend -Stamp -quit
CFLAGS  = -c -depend !Depend -zM -zps1 -fah ${INCLUDES} ${DFLAGS}
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

#
# Include files
#
INCLUDES = -IC:

DFLAGS   =

#
# Program specific options:
#
COMPONENT = KeyWatch
TARGET    = aof.KeyWatch

RM	  = rm.KeyWatch
RMD	  = rm.KeyWatchD

OBJS      = o.KeyWatchHd o.KeyWatch
OBJSD     = o.KeyWatchHd od.KeyWatch

LIBS     =
LIBSD    = C:remotedb.o.remotedbzm TCPIPLibs:o.socklibzm TCPIPLibs:o.inetlibzm

#
# Rule patterns
#
.SUFFIXES:  .od

.c.o:;      ${CC} ${CFLAGS} -ff -o $@ $<
.c.od:;     ${CC} ${CFLAGS} -DDEBUG -DREMOTE_DEBUG -o $@ $<
.cmhg.o:;   ${CMHG} -p -o $@ $<
.cmhg.h:;   ${CMHG} -p -d $@ $<
.s.o:;      ${AS} ${AFLAGS} $< $@

#
# build a relocatable module:
#
all: ${RM} h.KeyWatchHd

debug: ${RMD}

#
# RISC OS ROM build rules:
#
rom: ${TARGET}
        @echo ${COMPONENT}: rom module built

export: export_${PHASE}

export_hdrs: h.${COMPONENT}
        ${CP} h.${COMPONENT} ${EXP_HDR}.h.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: export complete (headers)

export_libs:
        @echo ${COMPONENT}: export complete (libs)

install_rom: ${TARGET}
        ${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: rom module installed

clean:
        ${WIPE} o.* ${WFLAGS}
        ${WIPE} od.* ${WFLAGS}
        ${WIPE} rm.* ${WFLAGS}
        ${WIPE} linked.* ${WFLAGS}
        ${WIPE} map.* ${WFLAGS}
        ${REMOVE} ${TARGET}
        ${REMOVE} h.KeyWatchHd
        ${STRIP}
        @echo ${COMPONENT}: cleaned

resources:
#        ${MKDIR} ${RESDIR}.KeyWatch
#        ${CP} Resources.${LOCALE}.Messages  ${RESDIR}.KeyWatch.Messages  ${CPFLAGS}
#        @echo ${COMPONENT}: resource files copied

#
# ROM target (re-linked at ROM Image build time)
#
${TARGET}: ${OBJS} ${ROMCSTUBS}
        ${LD} -o $@ -aof ${OBJS} ${LIBS} ${ROMCSTUBS}

#
# Final link for the ROM Image (using given base address)
#
rom_link:
        ${MKDIR} linked
        ${LD} -o linked.${COMPONENT} -rmf -base ${ADDRESS} ${TARGET} ${ABSSYM}
        ${CP} linked.${COMPONENT} ${LINKDIR}.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: rom_link complete

${RM}: ${OBJS} ${LIBS} ${CLIB}
        ${LD} -o $@ -module ${OBJS} ${LIBS} ${CLIB}

${RMD}: ${OBJSD} ${LIBSD} ${CLIB}
        ${LD} -o $@ -module ${OBJSD} ${LIBSD} ${CLIB}

KeyWatch.c: KeyWatchHd.h

# Dynamic dependencies:

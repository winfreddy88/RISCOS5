# Copyright 1996 Acorn Computers Ltd
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
# Makefile for BootVars component
#
# Re-written to be more useful by SAR, 3rd Oct 2002

COMPONENT ?= BootVars
TARGET    ?= ${COMPONENT}
ABS        = abs.${TARGET}

MKDIR     = do mkdir -p
CC        = cc
LD        = link
CP        = copy
WIPE      = wipe

CFLAGS    = -ITCPIPLibs:,C:,C:RMVersion -fafh -wp -DCOMPAT_INET4
CPFLAGS   = ~cfr~v 
WFLAGS    = ~c~v

LIBS      = C:RMVersion.o.RMVersion TCPIPLibs:o.socklib CLib:o.Stubs
OBJS      = o.main

#
# Rule patterns:
#
.SUFFIXES:      .h .c .o
.c.o:;          ${CC} ${CFLAGS} ${THROWBACK} -depend !Depend -c ${ZM} -ff -o $@ $<

#
# Main rules:
#
clean:
        ifthere o   then ${WIPE} o   ${WFLAGS}
        ifthere l   then ${WIPE} l   ${WFLAGS}
        ifthere abs then ${WIPE} abs ${WFLAGS}
        @echo ${COMPONENT}: cleaned

dirs:
        ${MKDIR} o
        ${MKDIR} abs

all:    ${COMPONENT}

install: ${COMPONENT}
        ${MKDIR} ${INSTDIR}
        ${CP} ${ABS} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: installed (ram)

#
# Static dependencies:
#
${COMPONENT}: ${OBJS} dirs
        ${LD} -output ${ABS} ${OBJS} ${LIBS}
        @echo ${COMPONENT}: built


#------------------------------------------------------------------------
# Dynamic dependencies:

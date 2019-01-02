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
# Makefile for CDReinit component
#
# Re-written to be more useful by SAR, 3rd Oct 2002


COMPONENT ?= CDReinit
TARGET    ?= ~${COMPONENT}
UTIL       = util.${TARGET}
 
MKDIR      = do mkdir -p
AS         = objasm
LD         = link
CP         = copy
WIPE       = wipe

AFLAGS     = ${THROWBACK} -depend !Depend -stamp -quit
CPFLAGS    = ~cfr~v
WFLAGS     = ~c~v

OBJS       = o.${COMPONENT}

#
# Rule patterns:
#
.SUFFIXES:  .o .s
.s.o:;      ${AS} ${AFLAGS} -o $@ $<

#
# Main rules:
#
clean:
        IfThere o    Then ${WIPE} o    ${WFLAGS}
        IfThere util Then ${WIPE} util ${WFLAGS}
        @echo ${COMPONENT}: cleaned

dirs:
        ${MKDIR} o
        ${MKDIR} util

all:    ${COMPONENT}

install: ${COMPONENT}
        ${MKDIR} ${INSTDIR}
        ${CP} ${UTIL} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: installed (ram)

#
# Static dependencies:
#
${COMPONENT}: ${OBJS} dirs
        ${LD} -bin -o ${UTIL} ${OBJS}
        SetType ${UTIL} Utility
        @echo ${COMPONENT}: built

#---------------------------------------------------------------------------
# Dynamic dependencies:

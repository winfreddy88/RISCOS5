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
# Makefile for Patch
#

#
# Program specific options:
#
TARGET  ?= ${COMPONENT}
INSTDIR ?= <Install$Dir>

# Generic options:
#
MKDIR   = do mkdir -p
AS      = objasm
CP      = copy
LD      = link
WIPE    = wipe

AFLAGS  = -depend !Depend ${THROWBACK} -stamp -quit
CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

#
# Generic rules:
#
all: util.${COMPONENT}
        @echo ${COMPONENT}: all complete.

clean:
        IfThere o    Then ${WIPE} o    ${WFLAGS}
        IfThere util Then ${WIPE} util ${WFLAGS}
        @echo ${COMPONENT}: clean complete.

install: util.${COMPONENT}
        ${MKDIR} ${INSTDIR}
        ${CP} util.${COMPONENT} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: install complete.

#
# Static dependencies:
#

dirs:
        ${MKDIR} o
        ${MKDIR} util

util.${COMPONENT}: dirs
        ${AS} ${AFLAGS} -o o.${COMPONENT} s.${COMPONENT}
        ${LD} -bin -o $@ o.${COMPONENT}
        SetType $@ Utility

#---------------------------------------------------------------------------
# Dynamic dependencies:

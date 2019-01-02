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
# Makefile for TxtDebug
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 19-May-99  BJGA         Created.
#

#
# Generic options:
#
MKDIR   = cdir
AS      = objasm
LD      = link
CP      = copy
RM      = remove
WIPE    = x wipe
ASFLAGS = -absolute -depend !Depend -throwback
LDFLAGS = -bin
CPFLAGS = ~cfr~v
WFLAGS  = ~cfr~v

#
# Program specific options:
#
COMPONENT = TxtDebug
SOURCE    = s.${COMPONENT}
OBJECT    = o.${COMPONENT}
TARGET    = rm.${COMPONENT}

#
# Generic rules:
#
all: ${TARGET}
        @echo ${COMPONENT}: module built

clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} rm ${WFLAGS}
        -stripdepnd
        @echo ${COMPONENT}: cleaned

${TARGET}: ${OBJECT}
        ${MKDIR} rm
        ${LD} ${LDFLAGS} -o $@ $?
        SetType $@ Module
        Access $@ RW/R

${OBJECT}: ${SOURCE}
        ${MKDIR} o
        ${AS} ${ASFLAGS} -o $@ ${SOURCE}

# Dynamic dependencies:

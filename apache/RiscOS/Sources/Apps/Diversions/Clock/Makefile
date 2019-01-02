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
# Makefile for Clock
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 05-Nov-94  AMcC   Updated for Black build
#

#
# Program specific options:
#
COMPONENT  = Clock
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

#
# Generic options:
#
MKDIR   = do mkdir -p
CP      = copy
RM      = remove
SQUISH  = squish
WIPE    = x wipe

CPFLAGS = ~cfr~v
SQFLAGS = -nolist
WFLAGS  = ~c~v

FILES =\
 $(LDIR).!Help\
 $(LDIR).!Run\
 $(RDIR).!RunImage\
 $(LDIR).!Sprites\
 $(LDIR).!Sprites22\
 $(LDIR).Messages

#
# Main rules:
#
all: ${FILES}
        @echo ${COMPONENT}: Application built (Disc}

install: ${FILES}
        ${MKDIR} ${INSTAPP}
        ${CP} ${LDIR}.!Help      ${INSTAPP}.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!Run       ${INSTAPP}.!Run       ${CPFLAGS}
        ${CP} ${RDIR}.!RunImage  ${INSTAPP}.!RunImage  ${CPFLAGS}
        ${CP} ${LDIR}.!Sprites   ${INSTAPP}.!Sprites   ${CPFLAGS}
        ${CP} ${LDIR}.!Sprites22 ${INSTAPP}.!Sprites22 ${CPFLAGS}
        ${CP} ${LDIR}.Messages   ${INSTAPP}.Messages   ${CPFLAGS}
        @echo ${COMPONENT}: Application installed {Disc}

clean:
        ${RM} ${RDIR}.!RunImage
        ${WIPE} crunched.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#
# Static dependencies:
#
${RDIR}.!RunImage: crunched.!RunImage
        ${SQUISH} ${SQFLAGS} -from crunched.!RunImage -to $@

crunched.!RunImage: bas.!RunImage
        crunch.!RunImage; BASIC

#---------------------------------------------------------------------------
# Dynamic dependencies:

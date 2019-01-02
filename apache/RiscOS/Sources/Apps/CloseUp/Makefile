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
# Makefile for CloseUp
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 05-Nov-94  AMcC   Updated for Black build
# 07-May-09  JDL    Automatically update _Version token in messages file
#

#
# Program specific options:
#
COMPONENT  = CloseUp
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

include StdTools

SQFLAGS    = -nolist
MSGVERSION = ${AWK} -f Build:AwkVers
MSGS       = Resources.GenMessage

FILES =\
 ${LDIR}.!Help \
 ${LDIR}.Templates \
 ${RDIR}.!Run \
 ${RDIR}.!RunImage \
 ${RDIR}.!Sprites \
 ${RDIR}.!Sprites22 \
 ${RDIR}.!Sprites11 \
 ${MSGS}

#
# Main rules:
#
all: ${FILES}
        @echo ${COMPONENT}: Application built (Disc)

install: ${FILES}
        ${MKDIR} ${INSTAPP}
        ${CP} ${LDIR}.!Help      ${INSTAPP}.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.Templates  ${INSTAPP}.Templates  ${CPFLAGS}
        ${CP} ${RDIR}.!Run       ${INSTAPP}.!Run       ${CPFLAGS}
        ${CP} ${RDIR}.!Boot      ${INSTAPP}.!Boot      ${CPFLAGS}
        ${CP} ${RDIR}.!RunImage  ${INSTAPP}.!RunImage  ${CPFLAGS}
        ${CP} ${MSGS}            ${INSTAPP}.Messages   ${CPFLAGS}
        ${MKDIR} ${INSTAPP}.Themes.Ursula
        ${MKDIR} ${INSTAPP}.Themes.Morris4
        ${CP} ${RDIR}.!Sprites           ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites22         ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites11         ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
        ${CP} ${RDIR}.Ursula.!Sprites    ${INSTAPP}.Themes.Ursula.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.Ursula.!Sprites22  ${INSTAPP}.Themes.Ursula.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.Morris4.!Sprites   ${INSTAPP}.Themes.Morris4.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.Morris4.!Sprites22 ${INSTAPP}.Themes.Morris4.!Sprites22 ${CPFLAGS}
        Access ${INSTAPP} /r
        Access ${INSTAPP}.* r/r
        @echo ${COMPONENT}: Application installed {Disc}

clean:
        ${RM} ${RDIR}.!RunImage
        ${RM} ${MSGS}
        ${WIPE} crunched.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#
# Static dependencies:
#
${RDIR}.!RunImage: crunched.!RunImage
        ${SQUISH} ${SQFLAGS} -from crunched.!RunImage -to $@

${MSGS}: LocalRes:Messages VersionNum
        ${MSGVERSION} LocalRes:Messages > $@

crunched.!RunImage: bas.!RunImage
        crunch.!RunImage; BASIC

#---------------------------------------------------------------------------
# Dynamic dependencies:

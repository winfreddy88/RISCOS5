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
# Makefile for Help
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
COMPONENT  = Help
APP        = !${COMPONENT}
ROM_MODULE = rm.${COMPONENT}
RDIR       = Resources
LDIR       = LocalRes:
MSGS       = Resources.GenMessage

#
# Export Paths for Messages module
#
RESDIR = <resource$dir>.Resources.${COMPONENT}
RESAPP = <resource$dir>.Apps.${APP}

include StdTools

FILES =\
 ${RDIR}.!Boot \
 LocalRes:!Help \
 LocalRes:!Run \
 ${RDIR}.!RunImage \
 LocalRes:Messages \
 LocalRes:Templates 

# Resources to be included in the ROM module (not in Messages module}
RESFILES =\
 ${RDIR}.!RunImage

#
# Main rules:
#
all: ${FILES}
        @echo ${COMPONENT}: Application built (Disc)

rom: ${ROM_MODULE}
        @echo ${COMPONENT}: Module built (ROM)

install: ${FILES} ${MSGS}
        ${MKDIR} ${INSTDIR}.${APP}
        |
        ${CP} ${RDIR}.!Boot      ${INSTDIR}.${APP}.!Boot     ${CPFLAGS}
        ${CP} LocalRes:!Help     ${INSTDIR}.${APP}.!Help     ${CPFLAGS}
        ${CP} LocalRes:!Run      ${INSTDIR}.${APP}.!Run      ${CPFLAGS}
        ${CP} ${RDIR}.!RunImage  ${INSTDIR}.${APP}.!RunImage ${CPFLAGS}
        ${CP} ${MSGS}            ${INSTDIR}.${APP}.Messages  ${CPFLAGS}
        ${CP} LocalRes:Templates ${INSTDIR}.${APP}.Templates ${CPFLAGS}
        |
        Access ${INSTDIR}.${APP}.* lr/r
        |
        @echo ${COMPONENT}: Application installed (Disc)

install_rom: ${ROM_MODULE}
        ${CP} ${ROM_MODULE} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: Module installed {ROM}

resources: ${LDIR}ROM.!RunLink ${MSGS}
        ${MKDIR} ${RESAPP}
        ${MKDIR} ${RESDIR}
        |
        ${CP} LocalRes:!Help         ${RESAPP}.!Help     ${CPFLAGS}
        ${CP} LocalRes:ROM.!Run      ${RESAPP}.!Run      ${CPFLAGS}
        |
        ${CP} ${LDIR}ROM.!RunLink    ${RESDIR}.!RunLink  ${CPFLAGS}
        ${CP} ${MSGS}                ${RESDIR}.Messages  ${CPFLAGS}
        ${CP} LocalRes:Templates     ${RESDIR}.Templates ${CPFLAGS}
        |
        @echo ${COMPONENT}: resource files copied to Messages module

clean:
        ${RM} ${ROM_MODULE}
        ${RM} ${RDIR}.!RunImage
        ${RM} ${LDIR}ROM.!RunLink
        ${RM} ${MSGS}
        ${RM} GenMessTmp
        ${XWIPE} o ${WFLAGS}
        ${XWIPE} crunched.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#
# Static dependencies:
#
${ROM_MODULE}: s.Main ${RESFILES}
        ${MKDIR} o
        ${AS} ${ASFLAGS} -o o.Main s.Main
        ${LD} -rmf -o $@ o.Main

${MSGS}: LocalRes:Messages VersionNum
        FAppend GenMessTmp LocalRes:Messages LocalRes:Tokens${ROMTOKENS}
        ${INSERTVERSION} GenMessTmp > $@

${RDIR}.!RunImage: crunched.!RunImage
        ${SQUISH} ${SQUISHFLAGS} -from crunched.!RunImage -to $@

crunched.!RunImage: bas.!RunImage
        crunch.!RunImage; BASIC

${LDIR}ROM.!RunLink: bas.!RunLink
        ${MKDIR} ${LDIR}ROM    
        ${SQUISH} ${SQUISHFLAGS} -from bas.!RunLink -to $@

#---------------------------------------------------------------------------
# Dynamic dependencies:

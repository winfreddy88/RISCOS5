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
# Makefile for Configure
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name    Description
# ----       ----    -----------
# 02-Nov-94  AMcC    Updated for Black build
# 30-Jan-95  AMcC    Configure/FontMerge now have separate installation
#

#
# Program specific options:
#
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
MSGVERSION = ${AWK} -f Build:AwkVers
MSGS       = Resources.GenMessage
CDEFINES   = -DBLUEROM -DSTANDALONE
CINCLUDES  = -IC:

include StdTools
include AppLibs
include StdRules

# Configure
FILES =\
 ${RDIR}.!Boot\
 ${LDIR}.!Help\
 ${LDIR}.!Run\
 ${MSGS}\
 ${RDIR}.Sprites\
 ${RDIR}.Sprites22\
 ${LDIR}.Templates\
 ${RDIR}.tile_1\
 abs.!RunImage

# Configure Redirection
REDIRFILES =\
 ${LDIR}.!Help\
 ${LDIR}.!RunRedir\

# FontMerge
FONTFILES =\
 ${RDIR}.FontMerge.!Run\
 ${LDIR}.FontMerge.Messages\
 abs.FontMerge

OBJS =\
 o.Apps\
 o.CMOS\
 o.configfile\
 o.Configure\
 o.econet\
 o.inetsetup\
 o.Filer\
 o.Floppies\
 o.Fonts\
 o.HardDiscs\
 o.Keyboard\
 o.Lock\
 o.Memory\
 o.Mouse\
 o.Printer\
 o.Screen\
 o.Sound\
 o.System\
 o.version\
 o.WimpFlags #o.ftrace

#
# Main rules:
#
all: ${FONTFILES} ${FILES}
        @echo ${COMPONENT}: Application built (Disc)

resources: resources-${TYPE}

resources-:
        @echo ${COMPONENT}: No resource files to copy

resources-Redir: ${REDIRFILES}
        |
        ${MKDIR} <Resource$Dir>.Apps.!Configure
        |
        ${CP} ${LDIR}.!Help      <Resource$Dir>.Apps.!Configure.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!RunRedir  <Resource$Dir>.Apps.!Configure.!Run       ${CPFLAGS}
        |
        @echo ${COMPONENT}: resource files copied to Messages module

install: install_${COMPONENT}; @

install_Configure: ${FILES}
        |
        ${MKDIR} ${INSTDIR}.!Configure
        |
        ${CP} ${RDIR}.!Boot      ${INSTDIR}.!Configure.!Boot      ${CPFLAGS}
        ${CP} ${LDIR}.!Help      ${INSTDIR}.!Configure.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!Run       ${INSTDIR}.!Configure.!Run       ${CPFLAGS}
        ${CP} abs.!RunImage      ${INSTDIR}.!Configure.!RunImage  ${CPFLAGS}
        ${CP} ${MSGS}            ${INSTDIR}.!Configure.Messages   ${CPFLAGS}
        ${CP} ${RDIR}.Sprites    ${INSTDIR}.!Configure.Sprites    ${CPFLAGS}
        ${CP} ${RDIR}.Sprites22  ${INSTDIR}.!Configure.Sprites22  ${CPFLAGS}
        ${CP} ${LDIR}.Templates  ${INSTDIR}.!Configure.Templates  ${CPFLAGS}
        ${CP} ${RDIR}.tile_1     ${INSTDIR}.!Configure.tile_1     ${CPFLAGS}
        |
        Access ${INSTDIR}.!Configure /r
        Access ${INSTDIR}.!Configure.* WR/r
        |
        @echo Configure: Application installed (Disc)

install_ConfigureRedir: ${REDIRFILES}
        |
        ${MKDIR} ${INSTDIR}.!Configure
        |
        ${CP} ${LDIR}.!Help      ${INSTDIR}.!Configure.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!RunRedir  ${INSTDIR}.!Configure.!Run       ${CPFLAGS}
        |
        Access ${INSTDIR}.!Configure /r
        Access ${INSTDIR}.!Configure.* WR/r
        |
        @echo Configure Redirection: Application installed (Disc)

install_FontMerge: ${FONTFILES}
        |
        ${MKDIR} ${INSTDIR}.FontMerge
        |
        ${CP} ${RDIR}.FontMerge.!Run      ${INSTDIR}.FontMerge.!Run      ${CPFLAGS}
        ${CP} abs.FontMerge               ${INSTDIR}.FontMerge.FontMerge ${CPFLAGS}
        ${CP} ${LDIR}.FontMerge.Messages  ${INSTDIR}.FontMerge.Messages  ${CPFLAGS}
        |
        Access ${INSTDIR}.FontMerge /r
        Access ${INSTDIR}.FontMerge.* WR/r
        |
        @echo FontMerge: Application installed (Disc)

clean:
        ${XWIPE} o.* ${WFLAGS}
        ${RM} abs.!RunImage
        ${RM} abs.FontMerge
        ${RM} ${MSGS}
        ${XWIPE} Test.Configure.* ${WFLAGS}
        ${XWIPE} Test.FontMerge ${WFLAGS}
        @echo ${COMPONENT}: cleaned

clean_all:
   -Destroy ${OBJS} ${MSGS} abs.!RunImage ${INSTDIR}.!Configure.!Boot \
         ${INSTDIR}.!Configure.!Help ${INSTDIR}.!Configure.!Run \
         ${INSTDIR}.!Configure.!RunImage ${INSTDIR}.!Configure.Messages \
         ${INSTDIR}.!Configure.Sprites ${INSTDIR}.!Configure.Sprites22 \
         ${INSTDIR}.!Configure.Templates \
         ${INSTDIR}.!Configure.tile_1

#
# Static dependencies:
#
abs.!RunImage: ${OBJS} ${RLIB} ${CLIB}
        ${LD} -o $@ ${OBJS} ${RLIB} ${CLIB}
        ${SQZ} $@

abs.FontMerge: o.FontMerge ${CLIB}
        ${LD} -o $@ o.FontMerge ${CLIB}
        ${SQZ} $@

${MSGS}: LocalRes:Messages VersionNum
        ${MSGVERSION} LocalRes:Messages > $@

#---------------------------------------------------------------------------
# Dynamic dependencies:

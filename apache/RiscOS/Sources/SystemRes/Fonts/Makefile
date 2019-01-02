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
# Makefile for Fonts
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 08-Nov-94  AMcC   Updated for Black build
# 31-Jan-95  AMcC   !Sprites23 no longer installed
#                   Installation simplified, access attributes set explicitly
#

#
# Program specific options:
#
COMPONENT  = Fonts
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

include StdTools

SYSTEM =\
 System.Fixed.f240x120\
 System.Fixed.f240x240\
 System.Fixed.IntMetrics\
 System.Fixed.Outlines\
 System.Medium.IntMetrics\
 System.Medium.Outlines

SELWYN =\
 Selwyn.Encoding\
 Selwyn.IntMetrics\
 Selwyn.Outlines

SIDNEY =\
 Sidney.Encoding\
 Sidney.IntMetrics\
 Sidney.Outlines

NEWHALL =\
 NewHall.Bold.IntMetrics\
 NewHall.Bold.Outlines\
 NewHall.Bold.Italic.IntMetrics\
 NewHall.Bold.Italic.Outlines\
 NewHall.Medium.IntMetrics\
 NewHall.Medium.Outlines\
 NewHall.Medium.Italic.IntMetrics\
 NewHall.Medium.Italic.Outlines

SASSOON =\
 Sassoon.Primary.Intmetric0\
 Sassoon.Primary.Outlines0\
 Sassoon.Primary.Bold.Intmetric0\
 Sassoon.Primary.Bold.Outlines0

PORTERHOUSE =\
 Portrhouse.Standard.IntMetrics\
 Portrhouse.Standard.x90y45

FONTS =\
 ${SYSTEM} \
 ${SELWYN} \
 ${SIDNEY} \
 ${NEWHALL} \
 ${SASSOON} \
 ${PORTERHOUSE}

FILES=\
 ${LDIR}.!Boot\
 ${LDIR}.!Help\
 ${LDIR}.!Run\
 ${LDIR}.!Sprites\
 ${FONTS}

#
# Main rules:
#
all: ${FILES} ${FONTS}
        @${ECHO} ${COMPONENT}: All built (Disc)

install: install_${INSTFLAG}; @

install_all: install_fonts install_app; @

install_app: ${FILES}
        ${MKDIR} ${INSTAPP}.Themes
        ${CP} LocalRes:!Boot      ${INSTAPP}.!Boot             ${CPFLAGS}
        ${CP} LocalRes:!Help      ${INSTAPP}.!Help             ${CPFLAGS}
        ${CP} LocalRes:!Run       ${INSTAPP}.!Run              ${CPFLAGS}
        ${CP} LocalRes:!Sprites   ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
        ${CP} LocalRes:!Sprites22 ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
        ${CP} LocalRes:!Sprites11 ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
        ${CP} LocalRes:Morris4    ${INSTAPP}.Themes.Morris4    ${CPFLAGS}
        ${CP} LocalRes:Ursula     ${INSTAPP}.Themes.Ursula     ${CPFLAGS}
        ${CHMOD} -R 444 ${INSTAPP}
        @${ECHO} ${COMPONENT}: Application installed

install_fonts: ${FONTS}
        ${CP} NewHall    ${INSTAPP}.NewHall    ${CPFLAGS}
        ${CP} Sassoon    ${INSTAPP}.Sassoon    ${CPFLAGS}
        ${CP} Selwyn     ${INSTAPP}.Selwyn     ${CPFLAGS}
        ${CP} Sidney     ${INSTAPP}.Sidney     ${CPFLAGS}
        ${CP} System     ${INSTAPP}.System     ${CPFLAGS}
        ${CP} Portrhouse ${INSTAPP}.Portrhouse ${CPFLAGS}
        ${RM} ${INSTAPP}.Portrhouse.Standard.Masters
        ${CHMOD} -R 444 ${INSTAPP}
        @${ECHO} ${COMPONENT}: Font definitions installed

clean:
        @${ECHO} ${COMPONENT}: cleaned

#---------------------------------------------------------------------------
# Dynamic dependencies:

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
# Makefile for T1ToFont 
#

COMPONENT  = T1ToFont
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = frontend convert encoding metrics type1 utils
CDEFINES   = -DTRUSTFONTBBOX=0
LIBS      += ${RLIB}
INSTAPP_FILES = !Help !Run !Boot !RunImage Messages Templates \
                !Sprites:Themes !Sprites11:Themes !Sprites22:Themes \
                Morris4.!Sprites:Themes.Morris4 Morris4.!Sprites22:Themes.Morris4 \
                Ursula.!Sprites:Themes.Ursula Ursula.!Sprites22:Themes.Ursula
INSTAPP_VERSION = Messages
INSTAPP_DEPENDS = Encodings

include CApp

Encodings:
        ${MKDIR} ${INSTAPP}${SEP}Encodings
        ${MKDIR} ${INSTAPP}${SEP}Encodings${SEP}Specials
        ${CP} Encodings${SEP}Greek     ${INSTAPP}${SEP}Encodings${SEP}Greek     ${CPFLAGS}
        ${CP} Encodings${SEP}Selwyn    ${INSTAPP}${SEP}Encodings${SEP}Selwyn    ${CPFLAGS}
        ${CP} Encodings${SEP}Sidney    ${INSTAPP}${SEP}Encodings${SEP}Sidney    ${CPFLAGS}
        ${CP} Encodings${SEP}Sussex    ${INSTAPP}${SEP}Encodings${SEP}Sussex    ${CPFLAGS}
        ${CP} Encodings${SEP}SysFixed  ${INSTAPP}${SEP}Encodings${SEP}SysFixed  ${CPFLAGS}
        ${CP} Encodings${SEP}SysFixed4 ${INSTAPP}${SEP}Encodings${SEP}SysFixed4 ${CPFLAGS}
        ${CP} Encodings${SEP}System    ${INSTAPP}${SEP}Encodings${SEP}System    ${CPFLAGS}
        ${CP} Encodings${SEP}TeX       ${INSTAPP}${SEP}Encodings${SEP}TeX       ${CPFLAGS}
        ${CP} Encodings${SEP}Specials${SEP}Accents_Dn ${INSTAPP}${SEP}Encodings${SEP}Specials${SEP}Accents_Dn ${CPFLAGS}
        ${CP} Encodings${SEP}Specials${SEP}Accents_Up ${INSTAPP}${SEP}Encodings${SEP}Specials${SEP}Accents_Up ${CPFLAGS}
        ${CP} Encodings${SEP}Specials${SEP}Adobe      ${INSTAPP}${SEP}Encodings${SEP}Specials${SEP}Adobe      ${CPFLAGS}
        ${CP} Encodings${SEP}Specials${SEP}Dummies    ${INSTAPP}${SEP}Encodings${SEP}Specials${SEP}Dummies    ${CPFLAGS}

# Dynamic dependencies:

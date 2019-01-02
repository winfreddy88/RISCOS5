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
# Makefile for HForm
#

COMPONENT  = HForm
TARGET     = !RunImage
CUSTOMLINK = custom
INSTTYPE   = app
INSTAPP_FILES = !Run !Boot !Help !RunImage \
       !Sprites:Themes !Sprites11:Themes !Sprites22:Themes \
       Ursula.!Sprites:Themes.Ursula Ursula.!Sprites22:Themes.Ursula \
       Morris4.!Sprites:Themes.Morris4 Morris4.!Sprites22:Themes.Morris4
INSTAPP_VERSION = Messages

include CApp

CINCLUDES  = -IC:

#
# Static dependencies:
#
!RunImage: crunched.!RunImage
        ${SQUISH} ${SQUISHFLAGS} -keep bas.Keep -from crunched.!RunImage -to $@

crunched.!RunImage: n.!RunImage
        ${RUN}crunch.!RunImage; BASIC

n.!RunImage: i.!RunImage
        ${MKDIR} n
        ${NUMBER} i.!RunImage $@

i.!RunImage: bas.!RunImage
        ${MKDIR} i
        ${CPREPRO} ${CINCLUDES} bas.!RunImage > $@

clean::
       ${RM} crunched.!RunImage
       ${XWIPE} n ${WFLAGS}
       ${XWIPE} i ${WFLAGS}

# Dynamic dependencies:

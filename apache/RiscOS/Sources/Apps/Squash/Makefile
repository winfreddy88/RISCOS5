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
# Makefile for !Squash
#

COMPONENT  = Squash
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = main squash debug
CDFLAGS    = -DDEBUG
LIBS       = ${RLIB}
CINCLUDES  = -IC:
INSTAPP_FILES = !Boot !Help !Run !RunImage Messages Squash Templates \
                !Sprites:Themes !Sprites11:Themes !Sprites22:Themes \
                Morris4.!Sprites:Themes.Morris4 Morris4.!Sprites22:Themes.Morris4 \
                Ursula.!Sprites:Themes.Ursula Ursula.!Sprites22:Themes.Ursula
INSTAPP_DEPENDS = Squash
INSTAPP_VERSION = Messages

include CApp

Squash: squash.c squash.h
        ${CC} ${FLAGS} -c -o utility.o -DUTILITY squash.c
        ${LD} -o Squash utility.o ${CLIB} 
        ${SQZ} ${SQZFLAGS} Squash

clean::
        ${RM} Squash

# Dynamic dependencies:

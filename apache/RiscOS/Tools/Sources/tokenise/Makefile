# Copyright 2003 Castle Technology Ltd
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
# Makefile for tokenise
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 11-Nov-03  BJGA         Created.
#

COMPONENT = tokenise
TARGET    = Tokenise

include StdTools
include StdRules

CFLAGS    += -fah
CINCLUDES = -IC:

LIBS      = 
DIRS      = o._dirs

all: ${TARGET}
        @echo ${COMPONENT}: built

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: installed

Clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @echo ${COMPONENT}: cleaned

${TARGET}: ${DIRS}
        ${CC} ${STDTOOLOPTIONS} ${CDEFINES} ${CINCLUDES} -o $@ c.tokenise
        ${SQZ} $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

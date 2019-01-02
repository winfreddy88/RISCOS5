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
# Makefile for Destroy
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 11-Nov-03  BJGA         Created.
#

COMPONENT = Destroy
TARGET    = ${COMPONENT}

include StdTools
include StdRules

CFLAGS    += -fah
CINCLUDES = -IC:

LIBS      = 
OBJS      = 
DIRS      = o._dirs

all: ${TARGET}
        @${ECHO} ${COMPONENT}: built

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: installed

clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${DIRS}
        ${CC} ${STDTOOLOPTIONS} ${CDEFINES} ${CINCLUDES} -o $@ c.destroy
        ${SQZ} $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

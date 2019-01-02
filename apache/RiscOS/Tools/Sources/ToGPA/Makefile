# Copyright 2002 Tematic Ltd
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
# Makefile for ToGPA
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 12-Dec-02  BJGA         Created
#

#
# Paths
#

#
# Generic options:
#
include StdTools
include AppLibs
include AppStdRule

DIRS=o._dirs

#
# Program specific options:
#
COMPONENT  = ToGPA
TARGET     = ToGPA

OBJS       = ToGPA.o
LIBS       = ${CLIB}

#
# Build rules:
#
all: ${TARGET}
        @${ECHO} ${COMPONENT}: tool built

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@${ECHO} ${COMPONENT}: tool installed in library

clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @${ECHO} ${COMPONENT}: cleaned

#
# Internal targets:
#
${DIRS}:
	${MKDIR} o
	${TOUCH} $@

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o ${COMPONENT} ${OBJS} ${LIBS}
        ${SQZ} ${SQZFLAGS} $@
        ${CHMOD} a+rx $@

# Dynamic dependencies:

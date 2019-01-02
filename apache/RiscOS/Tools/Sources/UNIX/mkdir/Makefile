# Copyright 2003 Tematic Ltd
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
# Makefile for mkdir
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 24-Jul-03  JRB          Created.
#

#
# Generic options:
#
include StdTools

#
# Paths
#

#
# Program specific options:
#
COMPONENT = mkdir
TARGET    = ${COMPONENT}
OBJS      = o.${TARGET}

DIRS      = o._dirs

#
# Rule patterns
#
include StdRules

#
# Build rules
#

all: ${TARGET}
        @${ECHO} ${COMPONENT}: utility built

install: ${TARGET}
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@echo ${COMPONENT}: tool installed in library

clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @echo ${COMPONENT}: cleaned

${DIRS}:
	${MKDIR} o
	${TOUCH} $@

#
# Final link
#
${TARGET}: ${OBJS} ${DIRS}
	${LD} -bin -o $@ ${OBJS}
	${SETTYPE} $@ &FFC

# Dynamic dependencies:

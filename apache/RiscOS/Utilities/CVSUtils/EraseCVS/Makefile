# Copyright 1997 Acorn Computers Ltd
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
# Makefile for EraseCVS
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 06 May 1997  RWB        New for !EraseCVS
# 23 Sep 1999  SNB        Added install: phase.
#

#
# Generic options:
#
include Makefiles:StdTools

CHMOD      = access
CHMODFLAGS = RW/R

#
# Libraries
#
include Makefiles:AppLibs
#
# Include files
#
CINCLUDES = -ITbox:,C:

include Makefiles:StdRules

# Program specific options:
#
COMPONENT := EraseCVS
APP       = ${INSTDIR}.!${COMPONENT}
TARGET    = !RunImage

OBJS      = o.main o.cmdline
DIRS      = o._dirs

#
# Build
#
all: ${TARGET}
        @echo ${COMPONENT}: all complete

clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} ${TARGET} ${WFLAGS}
        @echo ${COMPONENT}: cleaned

install: ${TARGET}
        ${MKDIR} ${INSTDIR}
        ${CP} Resources ${APP} ${CPFLAGS}
        ${SQZ} ${TARGET} ${APP}.${TARGET}
        ${CHMOD} ${APP} ${CHMODFLAGS}
        ${CHMOD} ${APP}.* ${CHMODFLAGS}
        @echo ${COMPONENT}: installed

#
# Target
#
${TARGET}: ${OBJS} ${TBOXLIBS} ${CLIB} ${DIRS}
        ${LD} -o $@ ${OBJS} ${TBOXLIBS} ${CLIB}

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

#
# Dynamic dependencies:

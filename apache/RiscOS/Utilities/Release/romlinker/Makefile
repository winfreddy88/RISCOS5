# Copyright 2001 Pace Micro Technology plc
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
# Makefile for makeexprom
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date        Name         Description
# ----        ----         -----------
# 16 Jan 2001 SNB          Created

#
# Paths
#
EXP_HDR = <export$dir>

#
# Generic options:
#
include Makefiles:StdTools

DIRS            =o._dirs

#
# Include files
#

# Program specific options:
#
COMPONENT = romlinker
APPTARGET = ${COMPONENT}

OBJS =\
 makeexprom.o\
 makerom.o\
 memory.o\
 filereader.o\
 filewriter.o\
 romlinker.o\
 symbols.o

CINCLUDES = -IC:CLX
CDEFINES  = -DRISCOS

include Makefiles:AppStdRule
include Makefiles:AppLibs

#
# Build
#
all: ${APPTARGET}
        @echo ${COMPONENT}: all complete

clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} ${APPTARGET} ${WFLAGS}
        @echo ${COMPONENT}: cleaned

install: ${APPTARGET}
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} ${APPTARGET} ${INSTDIR}.${APPTARGET} ${CPFLAGS}
        ${CP} docs.Notes ${INSTDIR}.Docs.${APPTARGET} ${CPFLAGS}
        @echo ${COMPONENT}: installed

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

#
# Target
#
${APPTARGET}: ${OBJS} ${CLIB} ${CLXLIB} ${DIRS}
        ${LD} -o $@ ${OBJS} ${CLXLIB} ${CLIB}
        ${SQZ} ${SQZFLAGS} $@
        ${CHMOD} a+rx $@

#
# Dynamic dependencies:

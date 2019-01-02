# Copyright 1999 Element 14 Ltd
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
# Makefile for FileCRC
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# When          Who     What
# ----          ---     ----
# 11/2/1999     DSC     Created
# 17/2/1999     DSC     Preproccess & Instrumentation targets added.
#

#
# Generic options:
#

LDFLAGS = $(EXTRALDFLAGS) -c++

#
# Different compile options - choose one
#
# use PRODUCTION_TEST_BUILD if you want to build the version used for
#  production test software, along with its compiler flags, bugs etcetera.


# Override any options by setting the OPTS in the Build options

CDEFINES = -DRISCOS ${CCEXTRA} ${OPTS}
include StdTools
include AppStdRule
include AppLibs

#
# Program specific options:
#
COMPONENT = FileCRC
TARGETSA  = Targets.FileCRC
OBJS      = dbug.o filecrc.o display.o crc.o
OBJSI     = i.dbug i.filecrc i.display
OBJSINST  = inst.display inst.filecrc inst.dbug inst.crc

LIBSD     = ${DEBUGLIB} ${NET5LIBS}

#
# Generic rules:
#
all: ${TARGETSA} local_dirs
        @echo ${COMPONENT}: all complete

install: ${TARGETSA} local_dirs
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGETSA} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: tool installed in library

preprocess: ${OBJSI} local_dirs
        @echo ${COMPONENT}: preprocess build complete

instrument: ${OBJSINST} inst.instlib
        $(LD) $(LDFLAGS) -o targets.filecrci ${OBJSINST} inst.instlib ${CLIB} ${LIBS} ${LIBSD} ${RLIB} ${EXTRALIBS}
        @echo ${COMPONENT}: instrument build complete

clean:
        ${WIPE} o.* ${WFLAGS}
        ${WIPE} i.* ${WFLAGS}
        ${WIPE} targets.* ${WFLAGS}
        ${WIPE} inst.* ${WFLAGS}
        ${RM} o
        ${RM} i
        ${RM} targets
        ${RM} linked
        ${RM} inst
        ${STRIP}
        @echo ${COMPONENT}: cleaned

local_dirs:
        ${MKDIR} o
        ${MKDIR} i
        ${MKDIR} targets
        ${MKDIR} inst

#
# Executable target (static link)
#
${TARGETSA}: ${OBJS} ${CLIB} ${LIBS} ${LIBSD} ${RLIB} ${EXTRALIBS}
        ${LD} $(LDFLAGS) -o $@ ${OBJS} ${CLIB} ${LIBS} ${LIBSD} ${RLIB} ${EXTRALIBS}

# Dynamic dependencies:

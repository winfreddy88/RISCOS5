# Copyright 2000 Pace Micro Technology plc
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
# Makefile for chmod
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 27-Aug-00  SNB          Created.
#

#
# Paths
#
CLXDIR  = C:CLX

#
# Generic options:
#
include Makefiles:StdTools

SQZFLAGS= -f

#
# Libraries
#
include Makefiles:AppLibs

DIRS=o._dirs

#
# Include files
#
CINCLUDES = -IC: -I${CLXDIR}
DFLAGS    = -DDDE -DNESTEDMAKEFILES

#
# Program specific options:
#
COMPONENT  = chmod
TARGET     = ${COMPONENT}
SOURCE     = 
EXPORTS    = 


OBJS=	chmod.o riscos.o

LIBS=	${CLXLIB} ${CLIB}

#
# Rule patterns
#
include Makefiles:StdRules

#
# build it
#
all:	${TARGET}

#
# RISC OS ROM build rules:
#
rom:
        @echo ${COMPONENT}: rom module built

export: export_${PHASE}

install_rom:
        @echo ${COMPONENT}: rom module installed
        
install: ${TARGET}
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@echo ${COMPONENT}: tool installed in library

clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @echo ${COMPONENT}: cleaned

export_hdrs: 
	@echo ${COMPONENT}: export complete (hdrs)

export_libs: 
        @echo ${COMPONENT}: export complete (libs)

${DIRS}:
	${MKDIR} o
	${TOUCH} $@

#
# Final link
#
${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
        ${SQZ} ${SQZFLAGS} $@

# Dynamic dependencies:

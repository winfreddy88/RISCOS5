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
# Makefile for FreePool transient
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name   Description
# ----           ----   -----------
# 05-Oct-2001    SAR    Created
#

#
# Program specific options:
#
COMPONENT  = FreePool
UTILITY    = util.${COMPONENT}

#
# Generic options:
#
MKDIR   = do mkdir -p
AS      = objasm
CP      = copy
LD      = link
RM      = remove
WIPE    = wipe
CHMOD   = Unix.chmod $(CHMODFLAGS)

CPFLAGS    = ~cfr~v
WFLAGS     = ~c~v
CHMODFLAGS = -R 0755
OFLAGS     = -depend !Depend ${THROWBACK}

#
# Objects
#
OBJS     = o.FreePool

#
# Rule patterns
#
.SUFFIXES: .oz .od .asm .o .Source .c
.Source.o:;          ${AS} ${OFLAGS} -o $@ $<

#
# Default rule
#
all: ${UTILITY}
        @echo ${COMPONENT}: all complete

#
# RISC OS ROM build rules:
#
clean:
        ifthere util     then ${WIPE} util     ${WFLAGS}
        ifthere o        then ${WIPE} o        ${WFLAGS}
        @echo ${COMPONENT}: cleaned

export_hdrs:
        @echo ${COMPONENT}: nothing to do.

export_libs:
        @echo ${COMPONENT}: nothing to do.

resources:
        @echo ${COMPONENT}: nothing to do.

rom:
        @echo ${COMPONENT}: nothing to do.

install_rom:
        @echo ${COMPONENT}: nothing to do.

rom_link:
        @echo ${COMPONENT}: nothing to do.

#
# RISC OS disc build rules:
#
install: ${UTILITY} dirs
        ${CP} ${UTILITY} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        $(CHMOD) $(INSTDIR)
        @echo ${COMPONENT}: installed to ${INSTDIR}

dirs:
        ${MKDIR} ${INSTDIR}

#
# Other rules:
#
${UTILITY}: util ${OBJS} o
        ${LD} -o $@ -bin ${OBJS}
        SetType $@ Utility
        ${CHMOD} $@

util:
	${MKDIR} util

o:
	${MKDIR} o

#---------------------------------------------------------------------------
# Dynamic dependencies:

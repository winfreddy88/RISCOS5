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
# Makefile for TrapError
#
# ***********************************
# ***	 C h a n g e   L i s t	  ***
# ***********************************
#
# Date		Version	Author	Description
# ----		-------	------	-----------
# 13-Apr2001    2001	SAR	Created.
#

#
# Paths:
#
EXP_HDR	= <Export$Dir>

#
# Generic options:
#
MKDIR	= do mkdir -p
AS	= objasm
LD	= link
CP	= copy
RM	= remove
WIPE	= wipe
SQUEEZE	= modsqz -v
CCFLAGS	= -c -depend !Depend -IC:
ASFLAGS	= -depend !Depend ${THROWBACK} -o ${OBJECT}
LDFLAGS	= -bin -o ${TARGET}
CPFLAGS	= ~cfr~v
WFLAGS	= ~cfr~v

#
# Program specific options:
#
COMPONENT = TrapError
SOURCE	  = Hdr.GetAll
TARGET	  = rm.TrapError
OBJECT	  = o.TrapError

#
# Generic rules:
#

all: ${TARGET}
	@echo ${COMPONENT}: disc module built

install: ${TARGET} dirs
	${MKDIR} ${INSTDIR}
	${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: disc module installed

rom: ${TARGET} dirs
	@echo ${COMPONENT}: rom module built

ram: ${TARGET} dirs
	${SQUEEZE} ${TARGET}
	@echo ${COMPONENT}: ram module built

install_rom: ${TARGET}
	${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: rom module installed

clean:
	${RM} ${TARGET}
	IfThere o  Then ${WIPE} o ${WFLAGS}
	IfThere rm Then ${WIPE} rm ${WFLAGS}
	@echo ${COMPONENT}: cleaned

dirs:
	${MKDIR} rm

${TARGET}: ${OBJECT}
	${LD} ${LDFLAGS} ${OBJECT}
	SetType $@ Module
	Access $@ rw/r

${OBJECT}: ${SOURCE}
	${MKDIR} o
	${AS} ${ASFLAGS} ${SOURCE}

# Dynamic dependencies:

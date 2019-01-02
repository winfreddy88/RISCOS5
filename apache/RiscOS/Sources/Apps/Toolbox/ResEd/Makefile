# Copyright 1998 Acorn Computers Ltd
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
# ResEd master Makefile
#
# ***********************************
# ***	 C h a n g e   L i s t	  ***
# ***********************************
# Date	     Name   Description
# ----	     ----   -----------
# 05-Jun-98  SNB    Created
#

COMPONENT = ResEd
INSTDIR  ?= <Install$Dir>
INSTAPP   = ${INSTDIR}.!${COMPONENT}

include StdTools

TGT_MAIN  = aif.!RunImage
TGT_MENU  = aif.menu
TGT_WIND  = aif.window
TGT_MISC  = aif.misc

COMMONLIB = sources.common.o.commonlib

# These are passed to the sub-makefiles so that they can locate their
# Templates files and !WinEdit (for header file regeneration)
TEMP_BASE = ^.^.Resources.!${COMPONENT}
WINEDIT = WINEDIT=<Build$Dir>.Apps.!WinEdit CFLAGS="-depend !Depend"

# Sub-Makefiles rely on TARGET macro being not empty - clean target needs
# to have some dummy setting to avoid errors.
DUMMYTARGET = TARGET=foo
MAKE	    = amu -E

build:
	${MKDIR} aif
	dir sources.common
	${MAKE} ${MFLAGS} ${MAKECMDGOALS}
	dir ^.^.sources.shell
	${MAKE} OUTPUT=^.^.${TGT_MAIN} ${MFLAGS} ${MAKECMDGOALS} ${WINEDIT} TEMPLATES=${TEMP_BASE}.Templates
	dir ^.^.sources.misc
	${MAKE} OUTPUT=^.^.${TGT_MISC} ${MFLAGS} ${MAKECMDGOALS} ${WINEDIT} TEMPLATES=${TEMP_BASE}.CSE.!Misc.Templates
	dir ^.^.sources.window
	${MAKE} OUTPUT=^.^.${TGT_WIND} ${MFLAGS} ${MAKECMDGOALS} ${WINEDIT} TEMPLATES=${TEMP_BASE}.CSE.!Window.Templates
	dir ^.^.sources.menu
	${MAKE} OUTPUT=^.^.${TGT_MENU} ${MFLAGS} ${MAKECMDGOALS} ${WINEDIT} TEMPLATES=${TEMP_BASE}.CSE.!Menu.Templates
	dir ^.^

install: build
	${MKDIR} ${INSTAPP}
	${CP} Resources.!${COMPONENT}.* ${INSTAPP}.* ${CPFLAGS}
	${INSERTVERSION} Resources.!${COMPONENT}.Messages > ${INSTAPP}.Messages 
	${CP} LocalUserIFRes:!Sprites   ${INSTAPP}.* ${CPFLAGS}
	IfThere LocalUserIFRes:!Sprites11 then ${CP} LocalUserIFRes:!Sprites11 ${INSTAPP}.* ${CPFLAGS}
	${CP} LocalUserIFRes:!Sprites22 ${INSTAPP}.* ${CPFLAGS}
	${CP} LocalUserIFRes:Sprites    ${INSTAPP}.* ${CPFLAGS}
	IfThere LocalUserIFRes:Sprites11 then ${CP} LocalUserIFRes:Sprites11  ${INSTAPP}.* ${CPFLAGS}
	${CP} LocalUserIFRes:Sprites22  ${INSTAPP}.* ${CPFLAGS}
	${SQZ} ${TGT_MENU} ${INSTAPP}.CSE.!Menu.!RunImage   ${SQZFLAGS}
	${SQZ} ${TGT_WIND} ${INSTAPP}.CSE.!Window.!RunImage ${SQZFLAGS}
	${SQZ} ${TGT_MISC} ${INSTAPP}.CSE.!Misc.!RunImage   ${SQZFLAGS}
	${SQZ} ${TGT_MAIN} ${INSTAPP}.!RunImage             ${SQZFLAGS}
	@echo ${COMPONENT}: installed (disc)

clean:
	${WIPE} aif ${WFLAGS}
	dir sources.menu
	${MAKE} clean ${MFLAGS} ${DUMMYTARGET}
	dir ^.^.sources.misc
	${MAKE} clean ${MFLAGS} ${DUMMYTARGET}
	dir ^.^.sources.window
	${MAKE} clean ${MFLAGS} ${DUMMYTARGET}
	dir ^.^.sources.common
	${MAKE} clean ${MFLAGS} ${DUMMYTARGET}
	dir ^.^.sources.shell
	${MAKE} clean ${MFLAGS} ${DUMMYTARGET}
	dir ^.^
	@echo ${COMPONENT}: cleaned

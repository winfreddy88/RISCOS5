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
# Project:   !PrintTool
# Whose sole purpose in life is to allow palettes to be tuned
# to an acceptable level.

#
# Paths
#
EXP_HDR = <export$dir>

# Libraries
#
CLIB       = CLIB:o.stubs
ABCLIB     = CLIB:o.ABCLib
CPPLIB	   = CppLib:o.c++lib
RLIB       = RISCOSLIB:o.risc_oslib
RSTUBS     = RISCOSLIB:o.rstubs
ROMSTUBS   = RISCOSLIB:o.romstubs
ROMCSTUBS  = RISCOSLIB:o.romcstubs
ABSSYM     = RISC_OSLib:o.AbsSym
TOOLBOXLIB = TBox:o.toolboxlib
EVENTLIB   = TBox:o.eventlib
WIMPLIB	   = TBox:o.wimplib

#
# Generic options:
#
MKDIR   = cdir
AS      = objasm
CC      = cc
C++	= c++
CMHG    = cmhg
CP      = copy
LD      = link
RM      = remove
WIPE    = x wipe
CD	= dir

# Debug flags

AFLAGS = -depend !Depend -Stamp -quit
CFLAGS  = -c -depend !Depend ${INCLUDES} ${DEBUG} -Throwback
C++FLAGS  = -c -depend !Depend ${INCLUDES} ${DEBUG} -Throwback
Linkflags = -aif -c++ -o $@
ObjAsmflags = -throwback -NoCache -depend !Depend
CPFLAGS = ~cfr~v
WFLAGS  = ~c~v
#
# Include files
#
INCLUDES = -IC:

COMPONENT = Printtool
TARGET    = !RunImage

OBJS      =	\
main.o		\
calib.o		\
display.o	\
drawfile.o	\
tboxclass.o	\
walkth.o	\
error.o		\
palchoose.o	\
prtablegen.o

#
# Rule patterns
#
.c++.o:;    ${C++} ${CFLAGS} -o $@ $<
.c.o:;      ${CC} ${CFLAGS} -o $@ $<
.cmhg.o:;   ${CMHG} -o $@ $<
.s.o:;      ${AS} ${AFLAGS} $< $@

#
# Build
#
all: ${TARGET} dirs
        @echo ${COMPONENT}: all complete
dirs:
        ${MKDIR} o

clean:
        ${WIPE} o.* ${WFLAGS}
        ${WIPE} ${TARGET} ${WFLAGS}
        @echo ${COMPONENT}: cleaned

# Final targets:
${TARGET}: ${OBJS} ${EVENTLIB} ${ABCLIB} ${WIMPLIB}
        ${LD} ${Linkflags} ${OBJS} ${COBJ} ${CLIB} ${CPPLIB} ${EVENTLIB} ${ABCLIB} ${WIMPLIB}


# Dynamic dependencies:

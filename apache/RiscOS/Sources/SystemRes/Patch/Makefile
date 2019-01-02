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
# Makefile for StrongARM AppPatcher
#

COMPONENT    = PatchApp
TARGET      ?= ${COMPONENT}
INSTDIR     ?= <Install$Dir>
OBJS         = Sigs.o sigfind.o new_osswi.o new_swic.o new_swical.o \
               patch.o new_dlib.o new_overmg.o new_osswib.o cmhgdefn.o

include StdTools
include ModuleLibs

CFLAGS      += ${C_MODULE} ${C_NO_STKCHK}

clean:
        ${WIPE} h.patch ${WFLAGS}
        ${WIPE} o       ${WFLAGS}
        ${WIPE} rm      ${WFLAGS}
        @echo ${COMPONENT}: cleaned

install: rm.${COMPONENT}
        ${MKDIR} ${INSTDIR}
        ${CP} rm.${COMPONENT} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @echo ${COMPONENT}: installed (disc)

# Static dependencies:

dirs:
        ${MKDIR} o
        ${MKDIR} rm

rm.PatchApp: ${OBJS} dirs
        ${LD} -rmf -o $@ ${OBJS} ${CLIB}

sigfind.o: sigfind.c
        %cc -APCS 3/26bit/fpe2 ${CFLAGS} -o $@ sigfind.c

patch.o: patch.c patch.h
        %cc -APCS 3/26bit/fpe2 ${CFLAGS} -o $@ patch.c

Sigs.o: Sigs.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ Sigs.s

new_osswi.o: new_osswi.s                  
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_osswi.s

new_swic.o: new_swic.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_swic.s

new_swical.o: new_swical.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_swical.s

new_dlib.o: new_dlib.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_dlib.s

new_overmg.o: new_overmg.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_overmg.s

new_osswib.o: new_osswib.s
        %ObjAsm -APCS 3/26bit ${ASFLAGS} -o $@ new_osswib.s

# Mark as 26 bit only, if you're not StrongARM aware by now you certainly aren't 32 bit safe
cmhgdefn.o: cmhg.cmhgdefn
        %cmhg -p -26bit cmhg.cmhgdefn -o $@

patch.h: cmhg.cmhgdefn
        %cmhg -p -26bit cmhg.cmhgdefn -d patch.h

# Dynamic dependencies:

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
# Makefile for hpcdtoppm

CC= cc
CFLAGS= -O -DRISCOS_TWEAK
LDFLAGS= -aif C:o.stubs
LN= link
RM= x wipe
RMFLAGS = ~C~VF
MV= rename
AR= libfile -c -o 
AR2= |stamp
SQUEEZE = squeeze
MKDIR = cdir 

# source files: JPEG library proper
OBJ=  main.o output.o color.o format.o tools.o error.o \
      ppm.o postscr.o const.o \
      libpbm1.o

# files included by source files
INCLUDES= config.h hpcdtoppm.h \
          pbm.h pbmplus.h pgm.h ppm.h version.h

# Make C into O
.c.o:
        $(CC) $(CFLAGS) -c $*.c

hpcdtoppm: ${OBJ}
        ${MKDIR} bin
        ${CC} -o bin.hpcdtoppm ${OBJ} ${VLIBS}
        ${LN} ${LDFLAGS} -o bin.hpcdtoppm ${OBJ} ${VLIBS}
        ${SQUEEZE} bin.hpcdtoppm

clean:
        $(RM) o.* ${RMFLAGS}
        $(RM) bin.hpcdtoppm ${RMFLAGS}
        $(RM) bin ${RMFLAGS}



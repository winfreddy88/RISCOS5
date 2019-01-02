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
# Makefile for PNGLib
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 1997-06-25 BAL          Created.
# 2001-06-13 ADH          Wipes o and z directories as well as contents.
#

#
# Paths
#
EXP_HDR = <export$dir>
LIBDIR = <Lib$Dir>

#
# Generic options:
#
MKDIR   = do mkdir -p
AS      = objasm
CP      = copy
CC      = cc
CM      = cmhg
RM      = remove
LD      = link
LB      = libfile
WIPE    = x wipe

CCFLAGS = -c -depend !Depend -ffa -throwback ${INCLUDES} ${DFLAGS}
ASFLAGS = -depend !Depend -Stamp -quit
CPFLAGS = ~cfr~v
LBFLAGS = -c
WFLAGS  = ~CFR~V

#
# Libraries
#
CLIB      = CLIB:o.stubs
RLIB      = RISCOSLIB:o.risc_oslib
RSTUBS    = RISCOSLIB:o.rstubs
ROMSTUBS  = RISCOSLIB:o.romstubs
ROMCSTUBS = RISCOSLIB:o.romcstubs
ABSSYM    = RISC_OSLib:o.AbsSym

#
# Include files
#
INCLUDES  = -IC:,C:zlib

#
# Symbols to predefine. Everything after the first
# line simply strips down pnglib to the bare
# minimum required for ImageLib. Pngtest won't
# work with these defined...
#
DFLAGS    = -DRISCOS -DPNG_DEBUG=0 -DPNG_NO_STDIO\
 -DPNG_READ_TRANSFORMS_NOT_SUPPORTED\
 -DPNG_READ_EXPAND_SUPPORTED\
 -DPNG_READ_PACK_SUPPORTED\
 -DPNG_READ_PACKSWAP_SUPPORTED\
 -DPNG_READ_16_TO_8_SUPPORTED\
 -DPNG_READ_FILLER_SUPPORTED\
 -DPNG_READ_GAMMA_SUPPORTED\
 -DPNG_READ_USER_TRANSFORM_SUPPORTED\
 -DPNG_READ_ANCILLARY_CHUNKS_NOT_SUPPORTED\
 -DPNG_READ_bKGD_SUPPORTED\
 -DPNG_READ_gAMA_SUPPORTED\
 -DPNG_READ_sBIT_SUPPORTED\
 -DPNG_READ_sRGB_SUPPORTED\
 -DPNG_READ_tRNS_SUPPORTED\
 -DPNG_WRITE_TRANSFORMS_NOT_SUPPORTED\
 -DPNG_WRITE_ANCILLARY_CHUNKS_NOT_SUPPORTED

#
# Program specific options:
#
COMPONENT  = o.libpng-lib
COMPONENTZ = o.libpng-lzm
SOURCE     = ...
TARGET     = ${COMPONENT}
TARGETZ    = ${COMPONENTZ}
EXPORTS    = ${EXP_HDR}.${COMPONENT}

OBJS =\
 o.png\
 o.pngerror\
 o.pngget\
 o.pngmem\
 o.pngpread\
 o.pngread\
 o.pngrio\
 o.pngrtran\
 o.pngrutil\
 o.pngset\
 o.pngtrans\
 o.pngwio\
 o.pngwrite\
 o.pngwtran\
 o.pngwutil

OBJSZ =\
 z.png\
 z.pngerror\
 z.pngget\
 z.pngmem\
 z.pngpread\
 z.pngread\
 z.pngrio\
 z.pngrtran\
 z.pngrutil\
 z.pngset\
 z.pngtrans\
 z.pngwio\
 z.pngwrite\
 z.pngwtran\
 z.pngwutil

#
# Rule patterns
#
.SUFFIXES: .o .s .h .cmhg .c .z
.c.o:;     ${CC} ${CCFLAGS} -o $@ $<
.c.z:;     ${CC} ${CCFLAGS} -zM -o $@ $<
.s.o:;     ${AS} ${ASFLAGS} -o $@ $<
.cmhg.o:;  ${CM} ${CMFLAGS} -o $@ $<
.cmhg.h:;  ${CM} ${CMFLAGS} -d $@ $<

#
# build a the library:
#
all install export_libs:	${COMPONENT} ${COMPONENTZ}

#
# RISC OS ROM build rules:
#
clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} z ${WFLAGS}
        @echo ${COMPONENT}: cleaned

export: export_libs export_hdrs

export_hdrs:
	@| Nothing to do

local_dirs:
	${MKDIR} o
	${MKDIR} z

#
# Final link
#
${TARGET}: ${OBJS} local_dirs
        ${LB} ${LBFLAGS} -o ${COMPONENT} ${OBJS}

${TARGETZ}: ${OBJSZ} local_dirs
	${LB} ${LBFLAGS} -o ${COMPONENTZ} ${OBJSZ}

pngtest: o.pngtest ${TARGET} ${CLIB} C:zlib.o.zlib
        ${LD} -o pngtest o.pngtest ${TARGET} ${CLIB} C:zlib.o.zlib


# Dynamic dependencies:

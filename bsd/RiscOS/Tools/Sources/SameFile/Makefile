# Makefile for simple file comparison program
# Copyright © 2007, 7th software
# All rights reserved.

#
# Program specific options:
#
COMPONENT ?= SameFile
TARGET     = Abs.${COMPONENT}
OBJS       = SameFile.o
EXPORTS    = 

include Makefiles:StdTools

#
# Paths:
#
EXP_HDR = <Export$Dir>

#
# Generic options:
#
AFLAGS    = -depend !Depend -Stamp -quit
CFLAGS    = -c -Wp -depend !Depend ${INCLUDES} ${DFLAGS} -Throwback
#CFLAGS    = -c -Wp -ff -depend !Depend ${INCLUDES} ${DFLAGS} -Throwback     <- use this to remove function names
CPFLAGS   = ~cfr~v
WFLAGS    = ~c~v
DFLAGS    = 

#
# Libraries:
#
CLIB      = CLIB:o.stubs
RLIB      = RISCOSLIB:o.risc_oslib
RSTUBS    = RISCOSLIB:o.rstubs
ABSSYM    = RISC_OSLib:o.AbsSym
ROMSTUBS  = RISCOSLIB:o.romstubs
ROMCSTUBS = RISCOSLIB:o.romcstubs

#
# Include files:
#
INCLUDES  = -IC:

#
# Rule patterns:
#
.c.o:;      ${CC} ${CFLAGS} -o $@ $<
.cmhg.o:;   ${CMHG} -o $@ $<
.s.o:;      ${AS} ${AFLAGS} $< $@

#
# Build rules:
#
all: ${TARGET}
	@echo ${COMPONENT}: application built

install: ${TARGET}
	${MKDIR} ${INSTDIR}
	${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: application installed

clean:
	${WIPE} o ${WFLAGS}
	${WIPE} Abs ${WFLAGS}
	${RM} ${TARGET}
	@echo ${COMPONENT}: application cleaned

dirs:
	${MKDIR} o
	${MKDIR} Abs

${TARGET}: ${OBJS} ${CLIB} dirs
	${LD} ${LDFLAGS} -o $@ ${OBJS} ${CLIB}
	${SQZ} $@

# Dynamic dependencies:

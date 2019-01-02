# Makefile for GNU flex
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 23-Jul-99  SNB          Created.
#

#
# Paths
#
DOCSFILE= ${INSTDIR}.Docs.${COMPONENT}

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
TOUCH   = create
SQZ	= squeeze
AWK	= gnu.gawk
WIPE    = x wipe
BFLEX   = bflex
FLEX    = gnu.flex
YACC	= GNU.bison

CCFLAGS = -c -depend !Depend -ffa ${INCLUDES} ${DFLAGS} ${THROWBACK} -Wabcdpns
YACCCFLAGS = ${CCFLAGS} -DYYDEBUG=0
ASFLAGS = -depend !Depend -Stamp -quit
CPFLAGS = ~cfr~v
LBFLAGS = -c
WFLAGS  = ~CFR~V
SQZFLAGS = -f
AWKFLAGS = -f ${AWKSCRIPT}
YACCFLAGS =


#
# Libraries
#
CLIB      = CLIB:o.stubs
RLIB      = RISCOSLIB:o.risc_oslib
RSTUBS    = RISCOSLIB:o.rstubs
ROMSTUBS  = RISCOSLIB:o.romstubs
ROMCSTUBS = RISCOSLIB:o.romcstubs
ABSSYM    = RISC_OSLib:o.AbsSym
#UNIXLIB	  = TCPIPLibs:o.unixlib

DIRS=o._dirs

#
# Include files
#
INCLUDES  = -IC: -ITCPIPLibs:
DFLAGS    = -DDDE -DHAVE_CONFIG_H -DPARAMS(x)=x

#
# Program specific options:
#
COMPONENT  = flex
TARGET     = ${COMPONENT}
BOOT	   = ${COMPONENT}
SOURCE     = 
EXPORTS    = 


OBJS=	ccl.o dfa.o ecs.o gen.o main.o misc.o nfa.o sym.o tblcmp.o yylex.o

BOOTOBJS=	skel.o initscan.o initparse.o
GENOBJS=	parse.o skel.o scan.o


LIBS=	${UNIXLIB} ${CLIB}

#
# Rule patterns
#
.c.o:;     ${CC} ${CCFLAGS} -o $@ $<
.s.o:;     ${AS} ${ASFLAGS} -o $@ $<
.cmhg.o:;  ${CM} ${CMFLAGS} -o $@ $<
.cmhg.h:;  ${CM} ${CMFLAGS} -d $@ $<

#
# build a the library:
#
all:	${TARGET}
	@|

${BFLEX}: ${OBJS} ${BOOTOBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${BOOTOBJS} ${LIBS}
        ${SQZ} ${SQZFLAGS} $@
	@echo Bootstrap flex tool has been built successfully

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	${CP} Docs.${COMPONENT} ${DOCSFILE} ${CPFLAGS}
	@echo Installation of tool ${COMPONENT} complete

#
# RISC OS ROM build rules:
#
rom: ${TARGET}
        @echo ${COMPONENT}: rom module built

export: export_${PHASE}

install_rom: ${TARGET}
        @echo ${COMPONENT}: rom module installed

clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} parse ${WFLAGS}
        ${RM} ${COMPONENT}
        ${RM} ${BFLEX}
        ${RM} skl.flexsed
        ${RM} h.parse
        ${RM} c.parse
        ${RM} c.scan
        ${RM} c.skel
        @echo ${COMPONENT}: cleaned

export_hdrs: 
	@echo ${COMPONENT}: export complete (hdrs)

export_libs: 
        @echo ${COMPONENT}: export complete (libs)

${DIRS}:
	${MKDIR} o
	create $@

#
# Final link
#
${TARGET}: ${OBJS} ${GENOBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o ${COMPONENT} ${OBJS} ${GENOBJS} ${LIBS}
        ${SQZ} ${SQZFLAGS} $@


# Static dependencies:

o.skel: c.skel
	${CC} ${CCFLAGS} -o $@ $*.c

c.skel: skl.flex
	sed -f skl.sedscript <skl.flex >skl.flexsed
	${AWK} -f skl.awkscript <skl.flexsed >$@

scan.o: scan.c
	${CC} ${CCFLAGS} -o $@ $*.c

initscan.o: initscan.c parse.h
	${CC} ${CCFLAGS} -o $@ $*.c

scan.c: l.scan ${BFLEX}
	${BFLEX} -t >c.scan l.scan

h.parse c.parse: y.parse
        ${MKDIR} $*
	${YACC} ${YACCFLAGS} --name-prefix=$* -d --output=$*.c y.$*
        ${CP} $*.c c.$* ${CPFLAGS}
        ${CP} $*.h h.$* ${CPFLAGS}

o.parse: c.parse
	${CC} ${YACCCFLAGS} -o $@ c.$*

# Dynamic dependencies:

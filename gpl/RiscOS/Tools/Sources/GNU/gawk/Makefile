# Makefile for GNU/gawk
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 18-Nov-03  BJGA         Created.
#

COMPONENT = GNU/gawk
TARGET    = gawk

include StdTools
include GCCRules

CC        = gcc
LD        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -I@
CDEFINES  = -DHAVE_CONFIG_H
LDFLAGS   = -munixlib -static

LIBS      = 
OBJS      = main.o array.o awktab.o builtin.o dfa.o eval.o field.o \
            gawkmisc.o getopt.o getopt1.o io.o missing.o \
            msg.o node.o random.o re.o regex.o sys.o
DIRS      = o._dirs

all: ${TARGET}
        @${ECHO} ${COMPONENT}: built

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: installed

clean:
        IfThere o Then ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
        elf2aif $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

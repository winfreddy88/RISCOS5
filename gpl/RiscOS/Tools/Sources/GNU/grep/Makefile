# Makefile for GNU/grep
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 17-Nov-03  BJGA         Recreated.
#

COMPONENT = GNU/grep
TARGETS   = egrep fgrep grep

include StdTools
include GCCRules

CC        = gcc
LD        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -I^.libgnu4
CDEFINES  = -DHAVE_CONFIG_H -DCHAR_BIT=8 -DUSING_POSIX\
            "-DDIFF_PROGRAM=\"diff\""\
            "-DGNU_PACKAGE=\"GNU grep\"" "-DVERSION=\"2.5a\""\
            -DPROTOTYPES=1
LDFLAGS   = -munixlib -static

LIBS      = ^.libgnu4.o.libgnu4
OBJS      = o.dfa o.grep o.kwset o.search
DIRS      = o._dirs

ifneq ($(THROWBACK),)
CFLAGS += -mthrowback
endif

all: ${TARGETS}
        @${ECHO} ${COMPONENT}: built

install: install_${INSTTYPE}

install_tool_egrep: egrep
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} egrep ${INSTDIR}.egrep ${CPFLAGS}
        @${ECHO} egrep: tool installed in library

install_tool_fgrep: fgrep
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} fgrep ${INSTDIR}.fgrep ${CPFLAGS}
        @${ECHO} fgrep: tool installed in library

install_tool_grep: grep
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} grep ${INSTDIR}.grep ${CPFLAGS}
        @${ECHO} grep: tool installed in library

clean:
        IfThere o then ${WIPE} o ${WFLAGS}
        destroy ${TARGETS}
        @${ECHO} ${COMPONENT}: cleaned

egrep:  o.greplaunch ${DIRS}
        link -o $@ o.greplaunch

fgrep:  o.greplaunch ${DIRS}
        link -o $@ o.greplaunch

grep:   ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
        elf2aif $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

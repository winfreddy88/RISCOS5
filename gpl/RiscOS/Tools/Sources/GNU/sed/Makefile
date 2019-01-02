# Makefile for GNU/sed
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 18-Nov-03  BJGA         Created.
#

COMPONENT = GNU/sed
TARGET    = Sed

include StdTools
include GCCRules

CC        = gcc
LD        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -I^.libgnu4 -I@ -Ilib
CDEFINES  = -DHAVE_CONFIG_H -Dlint -DVOID=void\
            "-DPACKAGE=\"sed\""\
            "-DVERSION=\"4.0.7\""\
            "-DSED_FEATURE_VERSION=\"4.0\""
LDFLAGS   = -munixlib -static

LIBS      = ^.libgnu4.o.libgnu4
OBJS      = o.compile o.execute o.regex o.sed o.fmt o.utils
DIRS      = o._dirs

ifneq ($(THROWBACK),)
CFLAGS += -mthrowback
endif

all: ${TARGET}
        @${ECHO} ${COMPONENT}: built

install: ${TARGET}
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: installed

clean:
        IfThere o then ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
        elf2aif $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

o.utils: lib.c.utils
        ${CC} ${CFLAGS} -MD -MF !!Depend -o $@ lib.c.utils
        @${PERL} Build:GCCDepend $@

# Dynamic dependencies:

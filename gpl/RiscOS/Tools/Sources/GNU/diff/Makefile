# Makefile for GNU/Diff
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 09-Nov-99  NB           Created.
# 11-Nov-03  BJGA         Recreated.
#

COMPONENT = GNUDiff
TARGET    = diff
INSTAPP   = ${INSTDIR}.^.^.Apps.!${COMPONENT}

include StdTools
include GCCRules

CC        = gcc
LD        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -I^.libgnu4
CDEFINES  = -DHAVE_CONFIG_H -DCHAR_BIT=8 -D_GNU_SOURCE -DVOID=void\
            -DWIFEXITED(x)=(x) -DWEXITSTATUS(x)=(x)\
            "-DDEFAULT_DIFF_PROGRAM=\"diff\""\
            "-DDEFAULT_EDITOR_PROGRAM=\"ed\""\
            "-DDIFF_PROGRAM=\"diff\""\
            "-DPR_PROGRAM=\"pr\""\
            "-DGNU_PACKAGE=\"GNU diffutils\"" "-DVERSION=\"2.7\""
LDFLAGS   = -munixlib -static

LIBS      = ^.libgnu4.o.libgnu4
OBJS      = o.version
cmp_Objs  = o.cmp $(OBJS)
diff_Objs = o.diff o.analyze o.dir o.io o.util o.context o.ed o.ifdef o.normal o.side $(OBJS)
diff3_Objs = o.diff3 $(OBJS)
sdiff_Objs = o.sdiff $(OBJS)

ifneq ($(THROWBACK),)
CFLAGS += -mthrowback
endif

all: ${TARGET}
        @${ECHO} ${COMPONENT}: built

install: install_${INSTTYPE}

install_tool: ${TARGET}
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@echo ${COMPONENT}: tool installed in library

install_: install_tool
        ${MKDIR} ${INSTAPP}
        ${CP} LocalRes:!Boot ${INSTAPP}.!Boot ${CPFLAGS}
        ${CP} LocalRes:!Run ${INSTAPP}.!Run ${CPFLAGS}
        ${CP} LocalRes:!Help ${INSTAPP}.!Help ${CPFLAGS}
        ${CP} LocalRes:!Sprites ${INSTAPP}.!Sprites ${CPFLAGS}
        ${CP} LocalRes:Messages ${INSTAPP}.Messages ${CPFLAGS}
        ${CP} LocalRes:Templates ${INSTAPP}.Templates ${CPFLAGS}
        ${AWK} -f Build:AwkVers descmode=1 < LocalRes:Desc > ${INSTAPP}.Desc
	${TIDYDESC}  ${INSTAPP}.Desc ${INSTAPP}.Desc
        @${ECHO} ${COMPONENT}: installed

clean:
        ifthere o then wipe o ~cfr~v
        ${RM} cmp
        ${RM} diff
        ${RM} diff3
        ${RM} sdiff
        @${ECHO} ${COMPONENT}: cleaned

cmp:    ${cmp_Objs} ${LIBS} o._dirs
        ${LD} ${LDFLAGS} -o $@ ${cmp_Objs} ${LIBS}
        elf2aif $@

diff:   ${diff_Objs} ${LIBS} o._dirs
        ${LD} ${LDFLAGS} -o $@ ${diff_Objs} ${LIBS}
        elf2aif $@

diff3:  ${diff3_Objs} ${LIBS} o._dirs
        ${LD} ${LDFLAGS} -o $@ ${diff3_Objs} ${LIBS}
        elf2aif $@

sdiff:  ${sdiff_Objs} ${LIBS} o._dirs
        ${LD} ${LDFLAGS} -o $@ ${sdiff_Objs} ${LIBS}
        elf2aif $@

o._dirs:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

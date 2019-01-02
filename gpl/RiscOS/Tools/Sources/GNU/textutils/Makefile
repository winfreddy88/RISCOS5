# Makefile for GNU/textutils
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 01-Dec-03  BJGA         Recreated.
#

COMPONENT = GNU/textutils
TARGETS   = gcat cksum comm csplit cut expand fmt fold head join md5sum nl \
            od paste pr ptx sha1sum sort split sum tac tail tr tsort \
            unexpand uniq wc

include StdTools
include GCCRules

CC        = gcc
LD        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -I^.libgnu4
CDEFINES  = -DHAVE_CONFIG_H -DUSING_POSIX\
            "-DGNU_PACKAGE=\"GNU textutils\""\
            "-DPACKAGE=\"GNU textutils\"" "-DVERSION=\"2.0.16\""\
            -DHAVE_DECL_WCWIDTH=0 -DHAVE_WCWIDTH=0
LDFLAGS   = -munixlib -static

LIBS      = ^.libgnu4.o.libgnu4
DIRS      = o._dirs

ifneq ($(THROWBACK),)
CFLAGS += -mthrowback
endif

all: ${TARGETS}
        @${ECHO} ${COMPONENT}: built

install: install_${INSTTYPE}

install_tool_wc: wc
        ${MKDIR} ${INSTDIR}.Docs
        ${CP} wc ${INSTDIR}.wc ${CPFLAGS}
        @${ECHO} wc: tool installed in library

clean:
        IfThere o then ${WIPE} o ${WFLAGS}
        destroy ${TARGETS}
        @${ECHO} ${COMPONENT}: cleaned

gcat:   o.cat ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.cat ${LIBS}
        elf2aif $@

cksum:  o.cksum ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.cksum ${LIBS}
        elf2aif $@

comm:   o.comm ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.comm ${LIBS}
        elf2aif $@

csplit: o.csplit ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.csplit ${LIBS}
        elf2aif $@

cut:    o.cut ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.cut ${LIBS}
        elf2aif $@

expand: o.expand ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.expand ${LIBS}
        elf2aif $@

fmt:    o.fmt ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.fmt ${LIBS}
        elf2aif $@

fold:   o.fold ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.fold ${LIBS}
        elf2aif $@

head:   o.head ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.head ${LIBS}
        elf2aif $@

join:   o.join ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.join ${LIBS}
        elf2aif $@

md5sum: o.md5 o.md5sum ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.md5 o.md5sum ${LIBS}
        elf2aif $@

nl:     o.nl ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.nl ${LIBS}
        elf2aif $@

od:     o.od ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.od ${LIBS}
        elf2aif $@

paste:  o.paste ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.paste ${LIBS}
        elf2aif $@

pr:     o.pr ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.pr ${LIBS}
        elf2aif $@

ptx:    o.ptx ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.ptx ${LIBS}
        elf2aif $@

sha1sum: o.sha1sum o.md5sum ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.sha1sum o.md5sum ${LIBS}
        elf2aif $@

sort:   o.sort ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.sort ${LIBS}
        elf2aif $@

split:  o.split ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.split ${LIBS}
        elf2aif $@

sum:    o.sum ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.sum ${LIBS}
        elf2aif $@

tac:    o.tac ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.tac ${LIBS}
        elf2aif $@

tail:   o.tail ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.tail ${LIBS}
        elf2aif $@

tr:     o.tr ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.tr ${LIBS}
        elf2aif $@

tsort:  o.tsort ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.tsort ${LIBS}
        elf2aif $@

unexpand: o.unexpand ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.unexpand ${LIBS}
        elf2aif $@

uniq:   o.uniq ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.uniq ${LIBS}
        elf2aif $@

wc:     o.wc ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ o.wc ${LIBS}
        elf2aif $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

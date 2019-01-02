# Makefile for libgnu
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 18-Nov-03  BJGA         Created.
#

COMPONENT = libgnu4
TARGET    = o.${COMPONENT}

include StdTools
include GCCRules

AR        = ar
ARFLAGS   = -rc -o
CC        = gcc
CFLAGS    = -c -O2 -munixlib ${CINCLUDES} ${CDEFINES} -Wall
CINCLUDES = -isystem @
CDEFINES  = -DHAVE_CONFIG_H -DEINVAL=4 -DCHAR_BIT=8 -D_GNU_SOURCE

OBJS      = o.argmatch o.basename o.closeout o.cmpbuf o.diacrit \
            o.error o.exclude o.exitfail o.file-access o.freesoft \
            o.getstr o.hard-locale o.human o.imaxtostr  o.linebuffer \
            o.long-options o.md5 o.obstack o.offtostr o.physmem \
            o.prepargs o.posixver o.quote o.quotearg o.quotesys o.readtokens \
            o.regex o.ro_fromunix o.ro_tounix o.ro_wild o.sha o.savedir \
            o.strftime o.strverscmp o.umaxtostr o.version-etc o.xmalloc \
            o.xstrdup o.xstrtol o.xstrtoul  o.xstrtoumax o.__ro_ext_getenv
DIRS      = o._dirs

ifneq ($(THROWBACK),)
CFLAGS += -mthrowback
endif

export: export_${PHASE}

export_hdrs:
        @${ECHO} ${COMPONENT}: export complete (hdrs)

export_libs: ${TARGET}
        @${ECHO} ${COMPONENT}: export complete (libs)

clean:
        IfThere o Then ${WIPE} o ${WFLAGS}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${AR} ${ARFLAGS} $@ ${OBJS} ${LIBS}

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

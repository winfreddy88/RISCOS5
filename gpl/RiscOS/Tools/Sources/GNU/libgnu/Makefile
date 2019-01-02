# Makefile for libgnu
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 18-Nov-03  BJGA         Created.
#

COMPONENT = libgnu
TARGET    = o.${COMPONENT}

include StdTools
include StdRules

CC        = gcc
CFLAGS    = -c -O2 -mlibscl -mamu ${CINCLUDES} ${CDEFINES}
CINCLUDES = -isystem @
CDEFINES  = -DHAVE_CONFIG_H -DEINVAL=4 -DCHAR_BIT=8

OBJS      = o.__ro_ext_getenv o.__ro_ifdot o.__ro_return_os_error \
            o.alloca o.argmatch o.basename o.closeout o.cmpbuf o.creat \
            o.dfa o.diacrit o.ds_error o.ds_getenv o.error o.exclude \
            o.execvp o.exitfail o.fdopen o.file-access \
            o.filename_lastdirchar o.fileno_to_name o.fnmatch o.freesoft \
            o.fstat o.get_escape o.getdate o.getline o.getopt o.getopt1 \
            o.getpass o.getstr o.hard-locale o.human o.imaxtostr \
            o.linebuffer o.long-options o.md5 o.mdwopt o.memcasecmp \
            o.memcoll o.memrchr o.movefile o.obstack o.offtostr o.open \
            o.physmem o.pipes o.posixtm o.posixver o.prepargs o.quote \
            o.quotearg o.quotesys o.readtokens o.regex o.ro_fromunix \
            o.ro_tounix o.ro_wild o.savedir o.sha o.stat o.stpcpy o.strdup \
            o.strftime o.strncasecmp o.strtoumax o.strverscmp o.substring \
            o.tmpnam o.umaxtostr o.utime o.version-etc o.xexit o.xmalloc \
            o.xstrdup o.xstrtod o.xstrtol o.xstrtoul o.xstrtoumax
DIRS      = o._dirs

export: export_${PHASE}

export_hdrs:
        @${ECHO} ${COMPONENT}: export complete (hdrs)

export_libs: ${TARGET}
        @${ECHO} ${COMPONENT}: export complete (libs)

clean:
        IfThere o Then ${WIPE} o ${WFLAGS}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${AR} ${ARFLAGS} -o $@ ${OBJS} ${LIBS}

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

# Makefile for Perl
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 11-Dec-03  BJGA         Recreated
#

COMPONENT = Perl
TARGET    = ${COMPONENT}
INSTAPP   = ${INSTDIR}.!${COMPONENT}

include StdTools
include StdRules
include AppLibs

CFLAGS   += -fa -wanp
CINCLUDES = -IC:
CDEFINES  = -DRISCOS -DCONSERVATIVE -DDEBUGGING
LIBS      = 
OBJS      = o.av \
            o.deb \
            o.doio \
            o.doop \
            o.dump \
            o.gv \
            o.hv \
            o.mg \
            o.miniplmain \
            o.op \
            o.perl \
            o.perly \
            o.pp \
            o.pp_ctl \
            o.pp_hot \
            o.pp_sys \
            o.regcomp \
            o.regexec \
            o.run \
            o.scope \
            o.sv \
            o.taint \
            o.toke \
            o.util \
            o.acorn \
            o.pipe
DIRS      = o._dirs

all: ${TARGET}
        @${ECHO} ${COMPONENT}: built

install: ${TARGET}
        ${MKDIR} ${INSTAPP}.Lib.ExtUtils.pm
        ${MKDIR} ${INSTAPP}.Lib.File.pm
        ${MKDIR} ${INSTAPP}.Lib.Getopt.pm.pm
        ${MKDIR} ${INSTAPP}.Lib.I18N.pm
        ${MKDIR} ${INSTAPP}.Lib.IPC.pm
        ${MKDIR} ${INSTAPP}.Lib.Math.pm
        ${MKDIR} ${INSTAPP}.Lib.Net.pm
        ${MKDIR} ${INSTAPP}.Lib.pl
        ${MKDIR} ${INSTAPP}.Lib.pm
        ${MKDIR} ${INSTAPP}.Lib.Search.pm
        ${MKDIR} ${INSTAPP}.Lib.Sys.pm
        ${MKDIR} ${INSTAPP}.Lib.Term.pm
        ${MKDIR} ${INSTAPP}.Lib.Test.pm
        ${MKDIR} ${INSTAPP}.Lib.Text.pm
        ${MKDIR} ${INSTAPP}.Lib.Time.pm
        ${MKDIR} ${INSTAPP}.riscos.pm
        ${MKDIR} ${INSTAPP}.riscos.work.rdbm
        ${MKDIR} ${INSTAPP}.scripts
        ${CP} Resources.!Boot                     ${INSTAPP}.!Boot                     ${CPFLAGS}
        ${CP} Resources.!Help                     ${INSTAPP}.!Help                     ${CPFLAGS}
        ${CP} Resources.!Run                      ${INSTAPP}.!Run                      ${CPFLAGS}
        ${CP} Resources.!Sprites                  ${INSTAPP}.!Sprites                  ${CPFLAGS}
        ${CP} Resources.Artistic                  ${INSTAPP}.Artistic                  ${CPFLAGS}
        ${CP} Resources.Copying                   ${INSTAPP}.Copying                   ${CPFLAGS}
        ${CP} Resources.Lib.chat2                 ${INSTAPP}.Lib.chat2                 ${CPFLAGS}
        ${CP} Resources.Lib.ExtUtils.pm.MakeMaker ${INSTAPP}.Lib.ExtUtils.pm.MakeMaker ${CPFLAGS}
        ${CP} Resources.Lib.ExtUtils.pm.typemap   ${INSTAPP}.Lib.ExtUtils.pm.typemap   ${CPFLAGS}
        ${CP} Resources.Lib.ExtUtils.pm.xsubpp    ${INSTAPP}.Lib.ExtUtils.pm.xsubpp    ${CPFLAGS}
        ${CP} Resources.Lib.File.pm.Basename      ${INSTAPP}.Lib.File.pm.Basename      ${CPFLAGS}
        ${CP} Resources.Lib.File.pm.CheckTree     ${INSTAPP}.Lib.File.pm.CheckTree     ${CPFLAGS}
        ${CP} Resources.Lib.File.pm.Find          ${INSTAPP}.Lib.File.pm.Find          ${CPFLAGS}
        ${CP} Resources.Lib.File.pm.Path          ${INSTAPP}.Lib.File.pm.Path          ${CPFLAGS}
        ${CP} Resources.Lib.GetOpt.pm.pm.Long     ${INSTAPP}.Lib.GetOpt.pm.pm.Long     ${CPFLAGS}
        ${CP} Resources.Lib.getopt.pm.pm.Std      ${INSTAPP}.Lib.getopt.pm.pm.Std      ${CPFLAGS}
        ${CP} Resources.Lib.I18N.pm.Collate       ${INSTAPP}.Lib.I18N.pm.Collate       ${CPFLAGS}
        ${CP} Resources.Lib.IPC.pm.Open2          ${INSTAPP}.Lib.IPC.pm.Open2          ${CPFLAGS}
        ${CP} Resources.Lib.IPC.pm.Open3          ${INSTAPP}.Lib.IPC.pm.Open3          ${CPFLAGS}
        ${CP} Resources.Lib.Math.pm.BigFloat      ${INSTAPP}.Lib.Math.pm.BigFloat      ${CPFLAGS}
        ${CP} Resources.Lib.Math.pm.BigInt        ${INSTAPP}.Lib.Math.pm.BigInt        ${CPFLAGS}
        ${CP} Resources.Lib.Math.pm.Complex       ${INSTAPP}.Lib.Math.pm.Complex       ${CPFLAGS}
        ${CP} Resources.Lib.Net.pm.Ping           ${INSTAPP}.Lib.Net.pm.Ping           ${CPFLAGS}
        ${CP} Resources.Lib.pl.abbrev             ${INSTAPP}.Lib.pl.abbrev             ${CPFLAGS}
        ${CP} Resources.Lib.pl.assert             ${INSTAPP}.Lib.pl.assert             ${CPFLAGS}
        ${CP} Resources.Lib.pl.bigfloat           ${INSTAPP}.Lib.pl.bigfloat           ${CPFLAGS}
        ${CP} Resources.Lib.pl.bigint             ${INSTAPP}.Lib.pl.bigint             ${CPFLAGS}
        ${CP} Resources.Lib.pl.bigrat             ${INSTAPP}.Lib.pl.bigrat             ${CPFLAGS}
        ${CP} Resources.Lib.pl.cacheout           ${INSTAPP}.Lib.pl.cacheout           ${CPFLAGS}
        ${CP} Resources.Lib.pl.chat2              ${INSTAPP}.Lib.pl.chat2              ${CPFLAGS}
        ${CP} Resources.Lib.pl.complete           ${INSTAPP}.Lib.pl.complete           ${CPFLAGS}
        ${CP} Resources.Lib.pl.ctime              ${INSTAPP}.Lib.pl.ctime              ${CPFLAGS}
        ${CP} Resources.Lib.pl.dotsh              ${INSTAPP}.Lib.pl.dotsh              ${CPFLAGS}
        ${CP} Resources.Lib.pl.dumpvar            ${INSTAPP}.Lib.pl.dumpvar            ${CPFLAGS}
        ${CP} Resources.Lib.pl.exceptions         ${INSTAPP}.Lib.pl.exceptions         ${CPFLAGS}
        ${CP} Resources.Lib.pl.fastcwd            ${INSTAPP}.Lib.pl.fastcwd            ${CPFLAGS}
        ${CP} Resources.Lib.pl.find               ${INSTAPP}.Lib.pl.find               ${CPFLAGS}
        ${CP} Resources.Lib.pl.finddepth          ${INSTAPP}.Lib.pl.finddepth          ${CPFLAGS}
        ${CP} Resources.Lib.pl.flush              ${INSTAPP}.Lib.pl.flush              ${CPFLAGS}
        ${CP} Resources.Lib.pl.ftp                ${INSTAPP}.Lib.pl.ftp                ${CPFLAGS}
        ${CP} Resources.Lib.pl.getcwd             ${INSTAPP}.Lib.pl.getcwd             ${CPFLAGS}
        ${CP} Resources.Lib.pl.getopt             ${INSTAPP}.Lib.pl.getopt             ${CPFLAGS}
        ${CP} Resources.Lib.pl.getopts            ${INSTAPP}.Lib.pl.getopts            ${CPFLAGS}
        ${CP} Resources.Lib.pl.hostname           ${INSTAPP}.Lib.pl.hostname           ${CPFLAGS}
        ${CP} Resources.Lib.pl.importenv          ${INSTAPP}.Lib.pl.importenv          ${CPFLAGS}
        ${CP} Resources.Lib.pl.look               ${INSTAPP}.Lib.pl.look               ${CPFLAGS}
        ${CP} Resources.Lib.pl.newgetopt          ${INSTAPP}.Lib.pl.newgetopt          ${CPFLAGS}
        ${CP} Resources.Lib.pl.open2              ${INSTAPP}.Lib.pl.open2              ${CPFLAGS}
        ${CP} Resources.Lib.pl.open3              ${INSTAPP}.Lib.pl.open3              ${CPFLAGS}
        ${CP} Resources.Lib.pl.perl5db            ${INSTAPP}.Lib.pl.perl5db            ${CPFLAGS}
        ${CP} Resources.Lib.pl.pwd                ${INSTAPP}.Lib.pl.pwd                ${CPFLAGS}
        ${CP} Resources.Lib.pl.shellwords         ${INSTAPP}.Lib.pl.shellwords         ${CPFLAGS}
        ${CP} Resources.Lib.pl.stat               ${INSTAPP}.Lib.pl.stat               ${CPFLAGS}
        ${CP} Resources.Lib.pl.syslog             ${INSTAPP}.Lib.pl.syslog             ${CPFLAGS}
        ${CP} Resources.Lib.pl.tainted            ${INSTAPP}.Lib.pl.tainted            ${CPFLAGS}
        ${CP} Resources.Lib.pl.termcap            ${INSTAPP}.Lib.pl.termcap            ${CPFLAGS}
        ${CP} Resources.Lib.pl.timelocal          ${INSTAPP}.Lib.pl.timelocal          ${CPFLAGS}
        ${CP} Resources.Lib.pl.validate           ${INSTAPP}.Lib.pl.validate           ${CPFLAGS}
        ${CP} Resources.Lib.pm.AnyDBM_Fil         ${INSTAPP}.Lib.pm.AnyDBM_Fil         ${CPFLAGS}
        ${CP} Resources.Lib.pm.AutoLoader         ${INSTAPP}.Lib.pm.AutoLoader         ${CPFLAGS}
        ${CP} Resources.Lib.pm.autosplit          ${INSTAPP}.Lib.pm.autosplit          ${CPFLAGS}
        ${CP} Resources.Lib.pm.benchmark          ${INSTAPP}.Lib.pm.benchmark          ${CPFLAGS}
        ${CP} Resources.Lib.pm.carp               ${INSTAPP}.Lib.pm.carp               ${CPFLAGS}
        ${CP} Resources.Lib.pm.cwd                ${INSTAPP}.Lib.pm.cwd                ${CPFLAGS}
        ${CP} Resources.Lib.pm.english            ${INSTAPP}.Lib.pm.english            ${CPFLAGS}
        ${CP} Resources.Lib.pm.env                ${INSTAPP}.Lib.pm.env                ${CPFLAGS}
        ${CP} Resources.Lib.pm.exporter           ${INSTAPP}.Lib.pm.exporter           ${CPFLAGS}
        ${CP} Resources.Lib.pm.FileHandle         ${INSTAPP}.Lib.pm.FileHandle         ${CPFLAGS}
        ${CP} Resources.Lib.pm.integer            ${INSTAPP}.Lib.pm.integer            ${CPFLAGS}
        ${CP} Resources.Lib.pm.less               ${INSTAPP}.Lib.pm.less               ${CPFLAGS}
        ${CP} Resources.Lib.pm.shell              ${INSTAPP}.Lib.pm.shell              ${CPFLAGS}
        ${CP} Resources.Lib.pm.sigtrap            ${INSTAPP}.Lib.pm.sigtrap            ${CPFLAGS}
        ${CP} Resources.Lib.pm.strict             ${INSTAPP}.Lib.pm.strict             ${CPFLAGS}
        ${CP} Resources.Lib.pm.subs               ${INSTAPP}.Lib.pm.subs               ${CPFLAGS}
        ${CP} Resources.Lib.pm.SubstrHash         ${INSTAPP}.Lib.pm.SubstrHash         ${CPFLAGS}
        ${CP} Resources.Lib.pm.tiehash            ${INSTAPP}.Lib.pm.tiehash            ${CPFLAGS}
        ${CP} Resources.Lib.Search.pm.Dict        ${INSTAPP}.Lib.Search.pm.Dict        ${CPFLAGS}
        ${CP} Resources.Lib.Sys.pm.Hostname       ${INSTAPP}.Lib.Sys.pm.Hostname       ${CPFLAGS}
        ${CP} Resources.Lib.Sys.pm.Syslog         ${INSTAPP}.Lib.Sys.pm.Syslog         ${CPFLAGS}
        ${CP} Resources.Lib.Term.pm.Cap           ${INSTAPP}.Lib.Term.pm.Cap           ${CPFLAGS}
        ${CP} Resources.Lib.Term.pm.Complete      ${INSTAPP}.Lib.Term.pm.Complete      ${CPFLAGS}
        ${CP} Resources.Lib.Test.pm.Harness       ${INSTAPP}.Lib.Test.pm.Harness       ${CPFLAGS}
        ${CP} Resources.Lib.Text.pm.abbrev        ${INSTAPP}.Lib.Text.pm.abbrev        ${CPFLAGS}
        ${CP} Resources.Lib.Text.pm.ParseWords    ${INSTAPP}.Lib.Text.pm.ParseWords    ${CPFLAGS}
        ${CP} Resources.Lib.Text.pm.soundex       ${INSTAPP}.Lib.Text.pm.soundex       ${CPFLAGS}
        ${CP} Resources.Lib.Text.pm.tabs          ${INSTAPP}.Lib.Text.pm.tabs          ${CPFLAGS}
        ${CP} Resources.Lib.Time.pm.Local         ${INSTAPP}.Lib.Time.pm.Local         ${CPFLAGS}
        ${CP} ${TARGET}                           ${INSTAPP}.Perl                      ${CPFLAGS}
        ${CP} Resources.riscos.pm.RDBM_File       ${INSTAPP}.riscos.pm.RDBM_File       ${CPFLAGS}
        ${CP} Resources.riscos.pm.RiscosLib       ${INSTAPP}.riscos.pm.RiscosLib       ${CPFLAGS}
        @${ECHO} ${COMPONENT}: installed

clean:
        ${WIPE} o ${WFLAGS}
        ${RM} ${TARGET}
        @${ECHO} ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${LIBS} ${DIRS}
        ${LD} ${LDFLAGS} -o $@ ${OBJS} ${LIBS} ${CLIB}
        ${SQZ} $@

${DIRS}:
        ${MKDIR} o
        ${TOUCH} $@

# Dynamic dependencies:

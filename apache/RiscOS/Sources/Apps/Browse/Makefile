# Copyright 2007 Castle Technology Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Makefile for Browser
# ====================
#

# ]----------------------------------------------------------------------------
# Editor directives: StrongED
# [----------------------------------------------------------------------------


# StrongED$Mode      = Make
# StrongED$WrapWidth = Line
# StrongED$FoldParm1 = ( "# [---", "# ]---" )
#
# Using folding makes this document much easier to edit. At the time of
# writing Zap doesn't seem to support it, so if you're a Zap addict but don't
# mind switching for a little while, try StrongED on this file. Use "Ctrl"
# with "Keypad +" or "Keypad -" to fold/unfold the whole document except the
# section containing the cursor. Once having done that to enter folding mode,
# use Shift instead of Ctrl to fold/unfold only the section under the cursor.


# ]----------------------------------------------------------------------------
# Change List
# [----------------------------------------------------------------------------


# Date		Name	Description
# ====		====	===========
# 1997-06-24	BAL	Created
# 1997-07-18	BAL	Tidied up for CVS.  Hooks are in place for a debug
#			build, but I'm not sure exactly what's required for
#			one so it'll probably need tweaking.
# 1997-07-22	ADH	Duly tweaked. Extras added to cope with test Browser
#			(bouncy blue arrow), Customer browser, Phoenix
#			(blue acorn), and Customer browser (spinning
#			acorn)  (spinning acorn) variants.
#			See ReadMe for details on which of these use
#			different object directories and which just have
#			different compile time options. Updated the clean
#			and clean_all rules. Took DFLAGS out of CFLAGS to
#			make changing options more flexible. Note that the
#			same .s directory is still currently used for all
#			builds. Did lots of other stuff, too.
# 1997-08-08	ADH	Got sick of having to scroll the task window right
#			all the time to see what was compiling, so played
#			around with the SUFFIXES (rule patterns) section
#			to make the run-time output more readable.
# 1997-08-17	ADH	Adding object files was a nightmare, so the objects
#			list has been unrolled to one per line. This makes
#			the MakeFile very tall, so a consistent comment
#			syntax has been ensured to allow folding text
#			editors to fold the text sensibly - start on
#			NL, hash, NL; end on hash, space, hyphen.
# 1997-08-28	ADH	Added Customer build. Not much to do in the Makefile
#			but needs the appropriate TaskObey files.
# 1998-04-30	ADH	Added JavaScript build support, including BASEFLAGS
#			in the compile-time options.
# 1998-07-02	ADH	Prior to 2.06 intermediate checkin, took out
#			-DJAVASCRIPT from DFLAGS and added comment about
#			needing to increase !Run file WimpSlot values.
# 1998-07-07	ADH	Tried to make JavaScript builds easier; if the
#			component to make is installj rather than install or
#			installd, then !Run, !Boot and About are sourced
#			from !RunJ, !BootJ and AboutJ. Define JSUFFIX on the
#			command line to be -DJAVASCRIPT if doing this, too.
#			The TARGET binary name should be suffixed with '_J',
#			since even though the exported copy in "Targets"
#			overwrites the current exported Customer, Desktop
#			or whatever build, you still probably want to keep
#			the previous symbols table.
# 1998-07-31	ADH	The above is insufficient; a link is still tried
#			with MemLib, NSPRLib and JSLib even though they
#			may ultimately not be included. So these must be
#			built at all times. In addition, note that
#			USE_MALLOC_REPLACEMENT is now defined in the
#			BASEFLAGS (i.e. defined for every build).
# 1998-09-10	ADH	Cleared up the whole MemLib issue through NSPRLib.
#			JS_USING_MEMLIB local option in Main.c controls
#			whether or not MemLib is ever used. The NSPRLib
#			based redefinition of malloc() etc. on a global
#			basis by adding "-DUSE_NSPRLIB_ALLOC_REGISTRATION"
#			has NOT been done by default here. Added also
#			lines to wipe CVS control files from exported
#			"About" directories (WFLAGS used at last!).
# 1998-10-08	ADH	ResJ now used for Res file of JavaScript builds;
#			needed as the Choices dialogue now has JS
#			specific regions. install_common now installs
#			anything in 'User' dir and wipes CVS control files
#			from the exported copy. 'resources' rule updated
#			similarly for both 'User' and 'About' directories.
# 1999-01-05	ADH	clean_all now also removes syms directory.
# 1999-03-30	ADH	HTMLLib: and ${LIBDIR}.ImageLib. don't exist as paths
#			anymore so now use LIBDIR etc. Now exports mono
#			sprites ([!]Sprites23). Tweaked CC args (-Wpc).
# 2000-11-10	ADH	DebugLib support added.
# 2001-06-13	ADH,SNB	Grotty hack to sort out command line length limits
#			with CC alias.
# 2005-03-08	ADH	Added NDEBUG to non-debug DFLAGS, since some areas
#			of the standard C headers use it (most notably
#			assert.h). Should've been there for about the last
#			8 years by the looks of things...
# 2005-04-26	ADH	DebugLib now has four external library dependencies
#			which must be included in debug builds. MemLib now
#			requires RISC_OSLib's rstubs.o. URIlib is no longer
#			held locally, but instead brought in from C: as it
#			should always have been. Added 'RMTry' to common
#			files.
# 2006-03-02	ADH	Much better ability to build individual variants
#			including proper support for a fully Unicode build
#			requiring a Unicode HTMLLib, or a non-Unicode
#			version with a non-Unicode HTMLLib. Customer hacks
#			for Customer deprecated (code removed). Application
#			builds now quite advanced, module builds neglected.
# 2006-03-03	ADH	Creates sorted symbols tables.
# 2007-10-17	ADH	Over ten years on :-) tidied up the build for ROOL
#			release, including attempts to remove dependencies
#			on proprietary components that were only used for
#			relatively obscure debugging cases anyway.


# ]----------------------------------------------------------------------------
# Generic options
# [----------------------------------------------------------------------------


LIBDIR		= C:
MKDIR		= do mkdir -p
AS		= objasm
CMHG		= cmhg
CP		= copy
LD		= link
RM		= remove
SQUEEZE		= squeeze
WIPE		= x wipe
SORTSYMS	= SortSymTab

# Ensure AMU truncates the command line suitably

CC = $(subst %*0,,${Alias$CC})

ifndef CC
CC = cc
endif

AFLAGS		= ${THROWBACK} -depend !Depend -nocache -stamp -quit
CFLAGS		= ${THROWBACK} -depend !Depend -ffa ${INCLUDES} -Wpc
LDFLAGS		= -rescan
CPFLAGS		= ~cfr~v
SQFLAGS		= -f
WFLAGS		= ~cf~vr


# ]----------------------------------------------------------------------------
# Program specific options
# [----------------------------------------------------------------------------


ifndef DEBUGFLAG
DEBUGFLAG =
endif

ifndef SUFFIX
SUFFIX =
endif

ifndef VARIANT
VARIANT = ${DEBUGFLAG}${SUFFIX}
endif

ifndef TARGET
TARGET = abs.!RI${VARIANT}
endif

ifndef OBJDIR
OBJDIR = o${VARIANT}
endif

ifndef INSTDIR
INSTDIR = Targets.${SYSTEM}.!${SYSTEM}
endif

COMPONENT	= Browse
APP		= !Browse
MODULE		= rm.!Browse
ROM_MODULE	= aof.Browse
LDIR		= Resources.${LOCALE}.${SYSTEM}


# ]----------------------------------------------------------------------------
# Export Paths for Messages module
# [----------------------------------------------------------------------------


RESDIR		= <resource$dir>.Resources2.${COMPONENT}
RESAPP		= <resource$dir>.Apps.${APP}


# ]----------------------------------------------------------------------------
# Build flags
# [----------------------------------------------------------------------------


# BASEFLAGS holds common compile time options that all builds will use.
# Others are for the standard Desktop build (plus debug) in various
# forms - JS, non-JS, Unicode, non-Unicode. "NDEBUG" in the base flags
# is to do with an external library header; the browser code uses
# 'TRACE' to switch debugging code on or off.
#
# Adding "-DUSE_NSPRLIB_ALLOC_REGISTRATIONS" may be useful for relevant
# special build projects.

BASEFLAGS	= -DCOMPAT_INET4 "-DSYSTEM=\"${SYSTEM}\"" -DRISCOS -DNSPR20 -DNDEBUG

# Additional build-dependent flags.

DFLAGS		= ${BASEFLAGS} -DSINGLE_USER
DUFLAGS		= ${DFLAGS} -DUNIFONT
DJFLAGS		= ${DFLAGS} -DJAVASCRIPT
DJUFLAGS	= ${DUFLAGS} -DJAVASCRIPT

DDFLAGS		= ${DFLAGS} -fn -DSTRICT_PARSER -DTRACE
DDUFLAGS	= ${DDFLAGS} -DUNIFONT
DDJFLAGS	= ${DDFLAGS} -DJAVASCRIPT
DDJUFLAGS	= ${DDUFLAGS} -DJAVASCRIPT

DZFLAGS		= ${BASEFLAGS} -DSINGLE_USER -DHIDE_CGI -DANTI_TWITTER
DZUFLAGS	= ${DZFLAGS} -DUNIFONT
DZJFLAGS	= ${DZFLAGS} -DJAVASCRIPT
DZJUFLAGS	= ${DZUFLAGS} -DJAVASCRIPT

DZDFLAGS	= ${DZFLAGS} -fn -DSTRICT_PARSER -DTRACE
DZDUFLAGS	= ${DZDFLAGS} -DUNIFONT
DZDJFLAGS	= ${DZDFLAGS} -DJAVASCRIPT
DZDJUFLAGS	= ${DZDUFLAGS} -DJAVASCRIPT


# ]----------------------------------------------------------------------------
# Libraries
# [----------------------------------------------------------------------------


CLIB		= CLib:o.stubs
ROMCSTUBS	= RISC_OSLib:o.romcstubs
ABSSYM		= RISC_OSLib:o.c_abssym
WRAPPER		= RISC_OSLib:s.ModuleWrap
HTMLLIB		= ${LIBDIR}HTMLLib.o.HTMLLib
IMAGELIB	= ${LIBDIR}ImageLib.o.ImageLib
PNGLIB		= ${LIBDIR}ImageLib.o.libpng-lib
PNGLIBZ		= ${LIBDIR}ImageLib.o.libpng-lzm
JPEGLIB		= ${LIBDIR}ImageLib.o.libjpeg
JPEGLIBZ	= ${LIBDIR}ImageLib.o.libjpeg-zm
ZLIB		= C:zlib.o.zlib
URILIB		= C:o.URI # Exported from the URI module
FLEXLIB		= tbox:o.flexlib
EVENTLIB	= tbox:o.eventlib
TOOLBOXLIB	= tbox:o.toolboxlib
WIMPLIB		= tbox:o.wimplib
RENDERLIB	= tbox:o.renderlib
INETLIB		= TCPIPLibs:o.inetlib
SOCKLIB		= TCPIPLibs:o.socklib
UNICODELIB	= C:Unicode.o.ucodelib
NSPRLIB		= C:NSPRLib.o.NSPRLib
JSLIB		= C:JSLib.o.JSLib
DEBUGLIB	= <Lib$Dir>.Debuglib.o.debuglib
DESKLIB		= <Lib$Dir>.Desk.o.Desk
DDTLIB		= <Lib$Dir>.Wild.o.Wild
WILDLIB		= <Lib$Dir>.DDTLib.o.DDTLib
MODMALLOCLIB	= <Lib$Dir>.ModMalloc.o.ModMalloc

# Libraries used by every build

LIBS_ALL = \
 ${URILIB} \
 ${TOOLBOXLIB} \
 ${WIMPLIB} \
 ${RENDERLIB}

# Libraries used by any application build

LIBS_APPS = ${LIBS_ALL} \
 ${CLIB} \
 ${FLEXLIB} \
 ${EVENTLIB} \
 ${INETLIB} \
 ${IMAGELIB} \
 ${PNGLIB} \
 ${JPEGLIB} \
 ${ZLIB} \
 ${UNICODELIB}

# Additional libraries for JavaScript applications

LIBS_APPS_JS = \
 ${JSLIB} \
 ${NSPRLIB}

# Additional libraries for debug applications

LIBS_APPS_DEBUG = \
 ${DEBUGLIB} \
 ${SOCKLIB} \
 ${DDTLIB} \
 ${WILDLIB} \
 ${MODMALLOCLIB} \
 ${DESKLIB}

# Libraries used by any module build

LIBS_MODULES = ${LIBS_ALL} \
 ${FLEXLIB}zm \
 ${EVENTLIB}m \
 ${INETLIB}zm \
 ${IMAGELIB}zm \
 ${PNGLIBZ} \
 ${JPEGLIBZ} \
 ${ZLIB}zm \
 ${UNICODELIB}z \
 ${JSLIB}zm \
 ${NSPRLIB}zm

# Additional libraries for JavaScript modules

LIBS_MODULES_JS = \
 ${JSLIB}zm \
 ${NSPRLIB}zm

# Additional libraries for debug modules

LIBS_MODULES_DEBUG = \
 ${DEBUGLIB}zm \
 ${SOCKLIB}zm \
 ${INETLIB}zm \
 ${DDTLIB}_M \
 ${WILDLIB}_M \
 ${MODMALLOCLIB}zm \
 ${DESKLIB}_M

# Libraries for simple, Unicode, JavaScript and JavaScript
# plus Unicode application builds. Then the same, but with
# debugging enabled.

LIBS     = ${LIBS_APPS}     ${HTMLLIB}
LIBSU    = ${LIBS_APPS}     ${HTMLLIB}U
LIBSJ    = ${LIBS}          ${LIBS_APPS_JS}
LIBSJU   = ${LIBSU}         ${LIBS_APPS_JS}

LIBSD    = ${LIBS_APPS}     ${HTMLLIB}         ${LIBS_APPS_DEBUG}
LIBSDU   = ${LIBS_APPS}     ${HTMLLIB}U        ${LIBS_APPS_DEBUG}
LIBSDJ   = ${LIBSD}         ${LIBS_APPS_JS}
LIBSDJU  = ${LIBSDU}        ${LIBS_APPS_JS}

# Same again, but for modules

LIBSZ    = ${LIBS_MODULES}  ${HTMLLIB}zm
LIBSZU   = ${LIBS_MODULES}  ${HTMLLIB}Uzm
LIBSZJ   = ${LIBSZ}         ${LIBS_MODULES_JS}
LIBSZJU  = ${LIBSZU}        ${LIBS_MODULES_JS}

LIBSZD   = ${LIBS_MODULES}  ${HTMLLIB}zm       ${LIBS_MODULES_DEBUG}
LIBSZDU  = ${LIBS_MODULES}  ${HTMLLIB}Uzm      ${LIBS_MODULES_DEBUG}
LIBSZDJ  = ${LIBSZD}        ${LIBS_MODULES_JS}
LIBSZDJU = ${LIBSZDU}       ${LIBS_MODULES_JS}

# ]----------------------------------------------------------------------------
# Include path and minimum file requirements
# [----------------------------------------------------------------------------


# Compiler inclusion path

INCLUDES	= -Itbox:,C:,${LIBDIR}HTMLLib,${LIBDIR}ImageLib,Libraries.URILib,TCPIPLibs:,C:NSPRLib,C:JSLib

# Minimum required files for any build

FILES = \
 ${LDIR}.!Boot \
 ${LDIR}.!Run \
 ${LDIR}.!Sprites \
 ${LDIR}.!Sprites22 \
 ${LDIR}.Messages \
 ${LDIR}.Res \
 ${TARGET}

# Minimum required for module build resources

RESFILES = \
 ${LDIR}.Sprites \
 ${LDIR}.!Sprites \
 ${LDIR}.!Sprites22


# ]----------------------------------------------------------------------------
# Lists of object files
# [----------------------------------------------------------------------------


# Object files used in all builds

OBJS_ALL = \
 ${OBJDIR}.About \
 ${OBJDIR}.Arrays \
 ${OBJDIR}.Authorise \
 ${OBJDIR}.Browser \
 ${OBJDIR}.Choices \
 ${OBJDIR}.Cookies \
 ${OBJDIR}.CSIM \
 ${OBJDIR}.DragBox \
 ${OBJDIR}.Encoding \
 ${OBJDIR}.EventLogs \
 ${OBJDIR}.Fetch \
 ${OBJDIR}.FetchHTML \
 ${OBJDIR}.FetchPage \
 ${OBJDIR}.Find \
 ${OBJDIR}.FontManage \
 ${OBJDIR}.Forms \
 ${OBJDIR}.Frames \
 ${OBJDIR}.FromROSLib \
 ${OBJDIR}.Global \
 ${OBJDIR}.Handlers \
 ${OBJDIR}.History \
 ${OBJDIR}.Images \
 ${OBJDIR}.ImgHistory \
 ${OBJDIR}.ItemInfo \
 ${OBJDIR}.JavaScript \
 ${OBJDIR}.List \
 ${OBJDIR}.Main \
 ${OBJDIR}.Markers \
 ${OBJDIR}.Memory \
 ${OBJDIR}.Menus \
 ${OBJDIR}.Meta \
 ${OBJDIR}.MimeMap \
 ${OBJDIR}.Mouse \
 ${OBJDIR}.Multiuser \
 ${OBJDIR}.Object \
 ${OBJDIR}.OpenURL \
 ${OBJDIR}.PlugIn \
 ${OBJDIR}.Printing \
 ${OBJDIR}.PrintStyle \
 ${OBJDIR}.Protocols \
 ${OBJDIR}.Redraw \
 ${OBJDIR}.RedrawCore \
 ${OBJDIR}.Reformat \
 ${OBJDIR}.RMA \
 ${OBJDIR}.Save \
 ${OBJDIR}.SaveDraw \
 ${OBJDIR}.SaveFile \
 ${OBJDIR}.SaveObject \
 ${OBJDIR}.SavePDF \
 ${OBJDIR}.SaveSHelp \
 ${OBJDIR}.SaveText \
 ${OBJDIR}.Scale \
 ${OBJDIR}.SetPBoxes \
 ${OBJDIR}.Tables \
 ${OBJDIR}.TGutils \
 ${OBJDIR}.TokenUtils \
 ${OBJDIR}.Toolbars \
 ${OBJDIR}.URIfile \
 ${OBJDIR}.URLstat \
 ${OBJDIR}.URLutils \
 ${OBJDIR}.URLveneer \
 ${OBJDIR}.Utils \
 ${OBJDIR}.Windows \
 o.ROSLib

# Additional object files for builds that use a local
# hotlist (REMOTE_HOTLIST is *un*defined), debug builds,
# UNIFONT builds and JAVASCRIPT builds.

OBJS_HOTLIST    = ${OBJDIR}.Hotlist
OBJS_DEBUG      = ${OBJDIR}.Trace
OBJS_UNICODE    = ${OBJDIR}.Unifont
OBJS_JAVASCRIPT = \
 ${OBJDIR}.JSconsts \
 ${OBJDIR}.JSdocument \
 ${OBJDIR}.JSnavigtr \
 ${OBJDIR}.JSscreen \
 ${OBJDIR}.JSURL \
 ${OBJDIR}.JSutils \
 ${OBJDIR}.JSwindow

# Standard application build, non-Unicode, non-JavaScript;
# Unicode, non-JavaScript; non-Unicode, JavaScript; and
# Unicode, JavaScript. Same for debug applications. All
# single user.

OBJS    = ${OBJS_ALL} ${OBJS_HOTLIST}
OBJSU   = ${OBJS_ALL} ${OBJS_HOTLIST}               ${OBJS_UNICODE}
OBJSJ   = ${OBJS_ALL} ${OBJS_HOTLIST}               ${OBJS_JAVASCRIPT}
OBJSJU  = ${OBJS_ALL} ${OBJS_HOTLIST}               ${OBJS_JAVASCRIPT} ${OBJS_UNICODE}

OBJSD   = ${OBJS_ALL} ${OBJS_HOTLIST} ${OBJS_DEBUG}
OBJSDU  = ${OBJS_ALL} ${OBJS_HOTLIST} ${OBJS_DEBUG} ${OBJS_UNICODE}
OBJSDJ  = ${OBJS_ALL} ${OBJS_HOTLIST} ${OBJS_DEBUG} ${OBJS_JAVASCRIPT}
OBJSDJU = ${OBJS_ALL} ${OBJS_HOTLIST} ${OBJS_DEBUG} ${OBJS_JAVASCRIPT} ${OBJS_UNICODE}

# ]----------------------------------------------------------------------------
# Rule patterns
# [----------------------------------------------------------------------------


.SUFFIXES: .o .ou .oj .oju .od .odu .odj .odju .oz .ozu .ozj .ozju .ozd .ozdu .ozdj .ozdju .s .c

# Application builds

.c.o:;		@echo
		@echo Compiling $< (simple application)
		@echo ${DFLAGS}
		@${CC} ${CFLAGS} ${DFLAGS}        -c -o $@ $<

.c.ou:;		@echo
		@echo Compiling $< (Unicode application)
		@echo ${DUFLAGS}
		@${CC} ${CFLAGS} ${DUFLAGS}       -c -o $@ $<

.c.oj:;		@echo
		@echo Compiling $< (JavaScript application)
		@echo ${DJFLAGS}
		@${CC} ${CFLAGS} ${DJFLAGS}       -c -o $@ $<

.c.oju:;		@echo
		@echo Compiling $< (JavaScript, Unicode application)
		@echo ${DJUFLAGS}
		@${CC} ${CFLAGS} ${DJUFLAGS}      -c -o $@ $<

# Debug application builds

.c.od:;		@echo
		@echo Compiling $< (debug application)
		@echo ${DDFLAGS}
		@${CC} ${CFLAGS} ${DDFLAGS}       -c -g -o $@ $<

.c.odu:;	@echo
		@echo Compiling $< (debug Unicode application)
		@echo ${DDUFLAGS}
		@${CC} ${CFLAGS} ${DDUFLAGS}      -c -g -o $@ $<

.c.odj:;	@echo
		@echo Compiling $< (debug JavaScript application)
		@echo ${DDJFLAGS}
		@${CC} ${CFLAGS} ${DDJFLAGS}      -c -g -o $@ $<

.c.odju:;	@echo
		@echo Compiling $< (debug JavaScript, Unicode application)
		@echo ${DDJUFLAGS}
		@${CC} ${CFLAGS} ${DDJUFLAGS}     -c -g -o $@ $<

# Module builds

.c.oz:;		@echo
		@echo Compiling $< (simple module)
		@echo ${DZFLAGS}
		@${CC} ${CFLAGS} ${DZFLAGS}       -c -zM -DROM -o $@ $<

.c.ozu:;	@echo
		@echo Compiling $< (Unicode module)
		@echo ${DZUFLAGS}
		@${CC} ${CFLAGS} ${DZUFLAGS}      -c -zM -DROM -o $@ $<

.c.ozj:;	@echo
		@echo Compiling $< (JavaScript module)
		@echo ${DZJFLAGS}
		@${CC} ${CFLAGS} ${DZJFLAGS}      -c -zM -DROM -o $@ $<

.c.ozju:;	@echo
		@echo Compiling $< (JavaScript, Unicode module)
		@echo ${DZJUFLAGS}
		@${CC} ${CFLAGS} ${DZJUFLAGS}     -c -zM -DROM -o $@ $<

# Debug module builds

.c.ozd:;	@echo
		@echo Compiling $< (debug module)
		@echo ${DZDFLAGS}
		@${CC} ${CFLAGS} ${DZDFLAGS}      -c -g -zM -DROM -o $@ $<

.c.ozdu:;	@echo
		@echo Compiling $< (debug Unicode module)
		@echo ${DZDUFLAGS}
		@${CC} ${CFLAGS} ${DZDUFLAGS}     -c -g -zM -DROM -o $@ $<

.c.ozdj:;	@echo
		@echo Compiling $< (debug JavaScript module)
		@echo ${DZDJFLAGS}
		@${CC} ${CFLAGS} ${DZDJFLAGS}     -c -g -zM -DROM -o $@ $<

.c.ozdju:;	@echo
		@echo Compiling $< (debug JavaScript, Unicode module)
		@echo ${DZDJUFLAGS}
		@${CC} ${CFLAGS} ${DZDJUFLAGS}    -c -g -zM -DROM -o $@ $<

# Generic assembly code

.s.o:;		@echo
		@echo Assembling $< (for all builds)
		@echo ${AFLAGS}
		@${AS} ${AFLAGS} $< $@


# ]----------------------------------------------------------------------------
# Static dependencies
# [----------------------------------------------------------------------------


# Application builds

abs.!RI: ${OBJS} ${LIBS} o.dirs
	@echo ${TARGET}
	@echo Linking simple application
	@echo
	${LD} ${LDFLAGS} -s syms.!RI -o $@ ${OBJS} ${LIBS}
	-${SORTSYMS} -name    syms.!RI syms.!RI_n { > null: }
	-${SORTSYMS} -address syms.!RI syms.!RI_a { > null: }
	${SQUEEZE} ${SQFLAGS} $@

abs.!RIu: ${OBJSU} ${LIBSU} o.dirs
	@echo
	@echo Linking Unicode application
	@echo
	${LD} ${LDFLAGS} -s syms.!RIu -o $@ ${OBJSU} ${LIBSU}
	-${SORTSYMS} -name    syms.!RIu syms.!RIu_n { > null: }
	-${SORTSYMS} -address syms.!RIu syms.!RIu_a { > null: }
	${SQUEEZE} ${SQFLAGS} $@

abs.!RIj: ${OBJSJ} ${LIBSJ} o.dirs
	@echo
	@echo Linking JavaScript application
	@echo
	${LD} ${LDFLAGS} -s syms.!RIj -o $@ ${OBJSJ} ${LIBSJ}
	-${SORTSYMS} -address syms.!RIj syms.!RIj_a { > null: }
	-${SORTSYMS} -name    syms.!RIj syms.!RIj_n { > null: }
	${SQUEEZE} ${SQFLAGS} $@

abs.!RIju: ${OBJSJU} ${LIBSJU} o.dirs
	@echo
	@echo Linking JavaScript, Unicode application
	@echo
	${LD} ${LDFLAGS} -s syms.!RIju -o $@ ${OBJSJU} ${LIBSJU}
	-${SORTSYMS} -name    syms.!RIju syms.!RIju_n { > null: }
	-${SORTSYMS} -address syms.!RIju syms.!RIju_a { > null: }
	${SQUEEZE} ${SQFLAGS} $@

# Debug application builds

abs.!RId: ${OBJSD} ${LIBSD} o.dirs
	@echo
	@echo Linking debug application
	@echo
	${LD} ${LDFLAGS} -debug -s syms.!RId -o $@ ${OBJSD} ${LIBSD}
	-${SORTSYMS} -name    syms.!RId syms.!RId_n { > null: }
	-${SORTSYMS} -address syms.!RId syms.!RId_a { > null: }

abs.!RIdu: ${OBJSDU} ${LIBSDU} o.dirs
	@echo
	@echo Linking debug Unicode application
	@echo
	${LD} ${LDFLAGS} -debug -s syms.!RIdu -o $@ ${OBJSDU} ${LIBSDU}
	-${SORTSYMS} -name    syms.!RIdu syms.!RIdu_n { > null: }
	-${SORTSYMS} -address syms.!RIdu syms.!RIdu_a { > null: }

abs.!RIdj: ${OBJSDJ} ${LIBSDJ} o.dirs
	@echo
	@echo Linking debug JavaScript application
	@echo
	${LD} ${LDFLAGS} -debug -s syms.!RIdj -o $@ ${OBJSDJ} ${LIBSDJ}
	-${SORTSYMS} -name    syms.!RIdj syms.!RIdj_n { > null: }
	-${SORTSYMS} -address syms.!RIdj syms.!RIdj_a { > null: }

abs.!RIdju: ${OBJSDJU} ${LIBSDJU} o.dirs
	@echo
	@echo Linking debug JavaScript, Unicode application
	@echo
	${LD} ${LDFLAGS} -debug -s syms.!RIdju -o $@ ${OBJSDJU} ${LIBSDJU}
	-${SORTSYMS} -name    syms.!RIdju syms.!RIdju_n { > null: }
	-${SORTSYMS} -address syms.!RIdju syms.!RIdju_a { > null: }

# Module builds

${MODULE}: oz.ModuleWrap ${OBJSZ} ${LIBSZ} ${CLIB} o.dirs
	@echo
	${LD} ${LDFLAGS} -s syms.RAMMod -o $@ -module oz.ModuleWrap ${OBJSZ} ${LIBSZ} ${CLIB}
	-${SORTSYMS} -name    syms.RAMMod syms.RAMMod_n { > null: }
	-${SORTSYMS} -address syms.RAMMod syms.RAMMod_a { > null: }

${ROM_MODULE}: oz.ModuleWrap ${OBJSZ} ${ROMCSTUBS} ${LIBSZ} o.dirs
	@echo
	${LD} ${LDFLAGS} -s syms.ROMMod -o $@ -aof oz.ModuleWrap ${OBJSZ} ${LIBSZ} ${ROMCSTUBS}
	-${SORTSYMS} -name    syms.ROMMod syms.ROMMod_n { > null: }
	-${SORTSYMS} -address syms.ROMMod syms.ROMMod_a { > null: }

rm.!BrowseD: ozd.ModuleWrap ${OBJSDZ} ${LIBSZ} o.dirs
	@echo
	${LD} ${LDFLAGS} -s syms.ROMDMod -o $@ -module oz.ModuleWrap ${OBJSDZ} ${LIBSZ}
	-${SORTSYMS} -name    syms.ROMDMod syms.ROMDMod_n { > null: }
	-${SORTSYMS} -address syms.ROMDMod syms.ROMDMod_a { > null: }


# ]----------------------------------------------------------------------------
# Main rules
# [----------------------------------------------------------------------------


all: ${FILES}
	@echo ${COMPONENT}: Application built (Disc)

rom: ${ROM_MODULE}
	@echo ${COMPONENT}: Module built (ROM)

# Install rule for all builds

install_common: ${FILES}
	@echo
	${MKDIR} ${INSTDIR}
	${CP} ${TARGET}				${INSTDIR}.!RunImage		${CPFLAGS}~n
	${CP} ${LDIR}.!Sprites			${INSTDIR}.!Sprites		${CPFLAGS}n
	${CP} ${LDIR}.!Sprites22		${INSTDIR}.!Sprites22		${CPFLAGS}n
	-${CP} ${LDIR}.!Sprites23		${INSTDIR}.!Sprites23		${CPFLAGS}n
	-${CP} ${LDIR}.5Sprites			${INSTDIR}.5Sprites		${CPFLAGS}n
	-${CP} ${LDIR}.5Sprites11		${INSTDIR}.5Sprites11		${CPFLAGS}n
	-${CP} ${LDIR}.5Sprites22		${INSTDIR}.5Sprites22		${CPFLAGS}n
	-${CP} ${LDIR}.RMTry			${INSTDIR}.RMTry		${CPFLAGS}~n
	${CP} ${LDIR}.8desktop			${INSTDIR}.8desktop		${CPFLAGS}n
	${CP} ${LDIR}.Choices			${INSTDIR}.Choices		${CPFLAGS}n
	${CP} ${LDIR}.Controls			${INSTDIR}.Controls		${CPFLAGS}n
	${CP} ${LDIR}.Messages			${INSTDIR}.Messages		${CPFLAGS}n
	${CP} ${LDIR}.Sprites			${INSTDIR}.Sprites		${CPFLAGS}n
	-${CP} ${LDIR}.Sprites22		${INSTDIR}.Sprites22		${CPFLAGS}n
	-${CP} ${LDIR}.Sprites23		${INSTDIR}.Sprites23		${CPFLAGS}n
	-${CP} ${LDIR}.User			${INSTDIR}.User			${CPFLAGS}n
	${WIPE} ${INSTDIR}.User.CVS	${WFLAGS}

# Default installation rule - uses the variant

install: install_${VARIANT}

# Non-JavaScript application installation

install_: install_common
	${CP} ${LDIR}.!Boot		${INSTDIR}.!Boot	${CPFLAGS}~n
	${CP} ${LDIR}.!Run		${INSTDIR}.!Run		${CPFLAGS}~n
	-${CP} ${LDIR}.About		${INSTDIR}.About	${CPFLAGS}~n
	-${CP} ${LDIR}.Res		${INSTDIR}.Res		${CPFLAGS}~n
	${WIPE} ${INSTDIR}.About.CVS	${WFLAGS}
	-Access ${INSTDIR}.*		wr/r
	-Access ${INSTDIR}.User.*	wr/r
	-Access ${INSTDIR}.About.*	wr/r
	@echo
	@echo ${COMPONENT}: Standard application installed to ${INSTDIR}

# JavaScript application installation

install_j: install_common
	${CP} ${LDIR}.!BootJ		${INSTDIR}.!Boot	${CPFLAGS}~n
	${CP} ${LDIR}.!RunJ		${INSTDIR}.!Run		${CPFLAGS}~n
	${CP} ${LDIR}.AboutJ		${INSTDIR}.About	${CPFLAGS}~n
	${CP} ${LDIR}.ResJ		${INSTDIR}.Res		${CPFLAGS}~n
	${WIPE} ${INSTDIR}.About.CVS	${WFLAGS}
	-Access ${INSTDIR}.*		wr/r
	-Access ${INSTDIR}.User.*	wr/r
	-Access ${INSTDIR}.About.*	wr/r
	@echo
	@echo ${COMPONENT}: JavaScript application installed to ${INSTDIR}

# Unicode application installation

install_u: install_
	@echo Unicode support is included

# JavaScript, Unicode application installation

install_ju: install_j
	@echo Unicode support is included

# Debug application installation

install_d: install_common
	${CP} ${LDIR}.!Boot		${INSTDIR}.!Boot	${CPFLAGS}~n
	${CP} ${LDIR}.!RunD		${INSTDIR}.!Run		${CPFLAGS}~n
	-${CP} ${LDIR}.About		${INSTDIR}.About	${CPFLAGS}~n
	-${CP} ${LDIR}.Res		${INSTDIR}.Res		${CPFLAGS}~n
	${WIPE} ${INSTDIR}.About.CVS	${WFLAGS}
	@echo
	@echo ${COMPONENT}: Debug application installed ${INSTDIR}

# Debug JavaScript application installation

install_dj: install_common
	${CP} ${LDIR}.!BootJ		${INSTDIR}.!Boot	${CPFLAGS}~n
	${CP} ${LDIR}.!RunD		${INSTDIR}.!Run		${CPFLAGS}~n
	-${CP} ${LDIR}.AboutJ		${INSTDIR}.About	${CPFLAGS}~n
	-${CP} ${LDIR}.ResJ		${INSTDIR}.Res		${CPFLAGS}~n
	${WIPE} ${INSTDIR}.About.CVS	${WFLAGS}
	@echo
	@echo ${COMPONENT}: Debug application installed ${INSTDIR}

# Unicode application installation

install_du: install_d
	@echo Unicode support is included

# JavaScript, Unicode application installation

install_dju: install_dj
	@echo Unicode support is included

# ROM application installation

install_rom: ${ROM_MODULE}
	${CP} ${ROM_MODULE} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo
	@echo ${COMPONENT}: Module installed (ROM)

# List of resources for module builds

resources:
	${MKDIR} ${RESDIR}
	${MKDIR} ${RESAPP}
	${MKDIR} ${RESDIR}.User
	${MKDIR} ${RESDIR}.About
	${CP} ${LDIR}.ROM.!Boot		${RESAPP}.!Boot		${CPFLAGS}
	${CP} ${LDIR}.ROM.!Run		${RESAPP}.!Run		${CPFLAGS}
	${CP} ${LDIR}.!Sprites		${RESDIR}.!Sprites	${CPFLAGS}
	${CP} ${LDIR}.!Sprites22	${RESDIR}.!Sprites22	${CPFLAGS}
	-${CP} ${LDIR}.!Sprites23	${RESDIR}.!Sprites23	${CPFLAGS}
	-${CP} ${LDIR}.5Sprites		${RESDIR}.5Sprites	${CPFLAGS}
	-${CP} ${LDIR}.5Sprites11	${RESDIR}.5Sprites11	${CPFLAGS}
	-${CP} ${LDIR}.5Sprites22	${RESDIR}.5Sprites22	${CPFLAGS}
	${CP} ${LDIR}.Choices		${RESDIR}.Choices	${CPFLAGS}
	${CP} ${LDIR}.Controls		${RESDIR}.Controls	${CPFLAGS}
	${CP} ${LDIR}.Messages		${RESDIR}.Messages	${CPFLAGS}
	${CP} ${LDIR}.Res		${RESDIR}.Res		${CPFLAGS}
	${CP} ${LDIR}.Sprites		${RESDIR}.Sprites	${CPFLAGS}
	-${CP} ${LDIR}.Sprites22	${RESDIR}.Sprites22	${CPFLAGS}
	-${CP} ${LDIR}.Sprites23	${RESDIR}.Sprites23	${CPFLAGS}
	${CP} ${LDIR}.User		${RESDIR}.User		${CPFLAGS}
	${CP} ${LDIR}.About		${RESDIR}.About		${CPFLAGS}
	${WIPE} ${RESDIR}.User.CVS	${WFLAGS}
	${WIPE} ${RESDIR}.About.CVS	${WFLAGS}
	@echo
	@echo ${COMPONENT}: Resource files copied to Messages module

clean:
	@echo starting
	${WIPE}	abs		${WFLAGS}
	${WIPE}	aof		${WFLAGS}
	${WIPE}	linked		${WFLAGS}
	${WIPE}	map		${WFLAGS}
	${WIPE}	o		${WFLAGS}
	${WIPE}	ou		${WFLAGS}
	${WIPE}	oj		${WFLAGS}
	${WIPE}	oju		${WFLAGS}
	${WIPE}	od		${WFLAGS}
	${WIPE}	odu		${WFLAGS}
	${WIPE}	odj		${WFLAGS}
	${WIPE}	odju		${WFLAGS}
	${WIPE}	oz		${WFLAGS}
	${WIPE}	ozu		${WFLAGS}
	${WIPE}	ozj		${WFLAGS}
	${WIPE}	ozju		${WFLAGS}
	${WIPE}	ozd		${WFLAGS}
	${WIPE}	ozdu		${WFLAGS}
	${WIPE}	ozdj		${WFLAGS}
	${WIPE}	ozdju		${WFLAGS}
	${WIPE}	rm		${WFLAGS}
	${RM}	s.AppName
	${RM}	s.ModuleWrap
	${RM}	o.dirs
	@echo
	@echo ${COMPONENT}: Cleaned

o.dirs:
	@${MKDIR} abs
	@${MKDIR} aof
	@${MKDIR} linked
	@${MKDIR} map
	@${MKDIR} o
	@${MKDIR} ou
	@${MKDIR} oj
	@${MKDIR} oju
	@${MKDIR} od
	@${MKDIR} odu
	@${MKDIR} odj
	@${MKDIR} odju
	@${MKDIR} oz
	@${MKDIR} ozu
	@${MKDIR} ozj
	@${MKDIR} ozju
	@${MKDIR} ozd
	@${MKDIR} ozdu
	@${MKDIR} ozdj
	@${MKDIR} ozdju
	@${MKDIR} rm
	@${MKDIR} syms
	@${MKDIR} Targets
	@${MKDIR} Targets.Browse
	@${MKDIR} Targets.Browse.!Browse
	@${MKDIR} Targets.Ursula
	@${MKDIR} Targets.Ursula.!Browse
	@${MKDIR} Targets.Phoenix
	@${MKDIR} Targets.Phoenix.!Phoenix
	create o.dirs
	stamp  o.dirs


# ]----------------------------------------------------------------------------
# Development rules
# [----------------------------------------------------------------------------


linkmap: ${OBJS} ${LIBS}
	${LD} ${LDFLAGS} -map -o null:x ${OBJS} ${LIBS} > map.linked

map:
	${LD} ${LDFLAGS} -map -bin -base 0 -o null: ${OBJS} ${LIBS} > map.base0

clean_all: clean
	${WIPE}	Targets		${WFLAGS}
	${WIPE}	Syms		${WFLAGS}
	@echo ${COMPONENT}: Cleaned all


# ]----------------------------------------------------------------------------
# Final link for ROM Image (using given base address)
# [----------------------------------------------------------------------------


rom_link:
	${LD} ${LDFLAGS} -o linked.${COMPONENT} -bin -base ${ADDRESS} \
		${ROM_MODULE} ${ABSSYM} -map > map.${COMPONENT}
	truncate map.${COMPONENT} linked.${COMPONENT}
	${CP} linked.${COMPONENT} ${LINKDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: rom_link complete

oz.ModuleWrap: s.ModuleWrap s.AppName ${RESFILES}
	${AS} ${AFLAGS} s.ModuleWrap $@

s.ModuleWrap: ${WRAPPER}
	${CP} ${WRAPPER} $@ ${CPFLAGS}

s.AppName: ${LDIR}.Messages
	awk -f awk.AppName ${LDIR}.Messages > $@


# ]----------------------------------------------------------------------------
# Dynamic dependencies:

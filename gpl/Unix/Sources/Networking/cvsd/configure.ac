# configure.ac - process this file with autoconf to produce configure
# Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Arthur de Jong
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

AC_PREREQ(2.59)
AC_COPYRIGHT(
[Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Arthur de Jong

This configure script is derived from configure.ac which is free software;
you can redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
See the configure.ac file for more details.])

# initialize and set version and bugreport address
AC_INIT([cvsd],[1.0.13],[arthur@ch.tudelft.nl])
RELEASE_MONTH="Aug 2006"
AC_SUBST(RELEASE_MONTH)
AC_CONFIG_SRCDIR(cvsd.c)

# display notice and initialize automake
AC_MSG_NOTICE([configuring AC_PACKAGE_TARNAME AC_PACKAGE_VERSION])
AM_INIT_AUTOMAKE(AC_PACKAGE_TARNAME,AC_PACKAGE_VERSION)

# create a config.h file (Automake will add -DHAVE_CONFIG_H)
AC_CONFIG_HEADERS([config.h])

# AJ_PROG_FIND(VARIABLE,PROG-TO-CHECK-FOR)
# ----------------------------------------
AC_DEFUN([AJ_PROG_FIND],[
  AC_ARG_WITH([$2],
              AS_HELP_STRING([--with-$2=PATH],
                             [specify location of $2 binary]),
              [if test "x$withval" = "x" || test "x$withval" = "xyes" || test "x$withval" = "xno"
               then
                 AC_MSG_ERROR([*** please specify the location of the $2 binary ***])
               else
                 $1="$withval"
               fi])
  if test -z "$$1"
  then
    AC_PATH_PROG($1,$2)
  fi
  if test -z "$$1"
  then
    AC_MSG_ERROR([*** '$2' not found, please install, fix your \$PATH or use --with-$2 ***])
  fi
  if test ! -r "$$1" || test "x`basename "$$1"`" != "x$2"
  then
    AC_MSG_WARN([$$1 does not look like the $2 binary])
  fi
  AC_SUBST([$1])
])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_LN_S
AC_PATH_PROG(CHMOD,chmod)
AC_SUBST(CHMOD)
AC_PATH_PROG(SED,sed)
if test -z "$SED" ; then
  AC_MSG_ERROR([*** 'sed' missing, please install or fix your \$PATH ***])
fi
AJ_PROG_FIND(CVS,cvs)
AC_DEFINE_UNQUOTED(CVS_LOCATION,"$CVS",[location of cvs program])
AJ_PROG_FIND(PERL,perl)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(string.h)
AC_CHECK_HEADERS(unistd.h)
AC_CHECK_HEADERS(errno.h)
AC_CHECK_HEADERS(syslog.h)
AC_CHECK_HEADERS(getopt.h)
AC_CHECK_HEADERS(pwd.h)
AC_CHECK_HEADERS(grp.h)
AC_CHECK_HEADERS(arpa/inet.h)
AC_CHECK_HEADERS(netinet/in.h)
AC_CHECK_HEADERS(sys/types.h)
AC_CHECK_HEADERS(sys/socket.h)
AC_CHECK_HEADERS(sys/time.h)
AC_CHECK_HEADERS(sys/resource.h)
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(signal.h)
AC_CHECK_HEADERS(sys/stat.h)
AC_CHECK_HEADERS(netdb.h)
AC_CHECK_HEADERS(fcntl.h)
AC_CHECK_HEADERS(stdarg.h)
AC_CHECK_HEADERS(stdio.h)

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_VOLATILE
AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_TYPE_SIGNAL
AC_TYPE_UID_T
AC_TYPE_SIZE_T
AC_CHECK_TYPE(socklen_t,,
    AC_DEFINE(socklen_t, size_t,
    [Define to `size_t' if not defined elswhere.]),
    [
#include <sys/types.h>
#include <sys/socket.h>])
AC_CHECK_TYPE(struct sockaddr_storage,,
    AC_DEFINE(sockaddr_storage,sockaddr_in,
    [Define to 'sockaddr_in' if not defined elsewhere.]),
    [
#include <sys/types.h>
#include <sys/socket.h>])

# Checks for library functions.
AC_FUNC_FORK
AC_SEARCH_LIBS(gethostbyname,nsl socket)
AC_SEARCH_LIBS(socket,socket)
AC_CHECK_FUNCS([malloc dup2 inet_ntoa strchr strrchr strerror strtol atexit sigaction \
                memset memcpy sigemptyset select fcntl snprintf vsnprintf socket], ,
    AC_MSG_ERROR([*** we really need this function ***]))
AC_CHECK_FUNCS(nice setpriority setgroups gethostbyname)
AC_FUNC_SELECT_ARGTYPES

# Only include Limit operations if system has setrlimit()
AC_CHECK_FUNCS(setrlimit,
    [AC_LIBOBJ(reslimit)],
    AC_MSG_NOTICE([disabling use of resource limits]))

# Replace getopt_long() function if it is not on the system
AC_CHECK_FUNCS(getopt_long, ,
    [AC_MSG_NOTICE([using own getopt_long() replacement])
     AC_LIBOBJ(getopt_long)])

# Replace daemon() function if it is not on the system
AC_SEARCH_LIBS(daemon,bsd)
AC_CHECK_FUNCS(daemon, ,
    [AC_MSG_NOTICE([using own daemon() replacement])
     AC_LIBOBJ(daemon)])

# check for getaddrinfo() and getnameinfo() and replace if not available
AC_SEARCH_LIBS(getaddrinfo,socket)
AC_CHECK_FUNCS(getaddrinfo getnameinfo freeaddrinfo gai_strerror)
AC_CHECK_TYPE(struct addrinfo,,,[
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>])
if test "$ac_cv_func_getaddrinfo" != yes || \
   test "$ac_cv_func_getnameinfo" != yes
then
  AC_MSG_NOTICE([using own getaddrinfo() and getnameinfo() replacements])
  AC_LIBOBJ(getinfos)
  AC_CHECK_FUNCS(getservbyname getservbyport gethostbyaddr htons hstrerror)
fi

# Check for debugging options
AC_ARG_ENABLE(debug,
              AS_HELP_STRING([--enable-debug],
                             [enable extensive debugging and logging]),
              [if test "x$enableval" != "no" ; then CFLAGS="-g -DDEBUG $CFLAGS" ; fi])

# Check for extra compiler warnings
AC_ARG_ENABLE(warnings,
              AS_HELP_STRING([--enable-warnings],
                             [enable extra compiler warnings (gcc)]),
              [if test "x$enableval" != "no" ; then CFLAGS="$CFLAGS -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Waggregate-return -Wmissing-declarations" ; fi])

# check wether we want use tcp wrappers (yes,no,maybe)
WANT_LIBWRAP="no"
AC_ARG_WITH(libwrap,
            AS_HELP_STRING([--with-libwrap@<:@=PATH@:>@],
                           [enable tcp wrapper support (disabled by default)]),
            [if test "x$withval" = "xno"
             then
               WANT_LIBWRAP="no"
             else
               WANT_LIBWRAP="yes"
               # add supplied value to paths
               if test "x$withval" != "x" && test "x$withval" != "xyes"
               then
                 CPPFLAGS="-I$LIBWRAP/include $CPPFLAGS"
                 LDFLAGS="-L$LIBWRAP/lib $LDFLAGS"
               fi
             fi])

# check wether we can use tcp wrappers
if test "x$WANT_LIBWRAP" != "xno"
then
  AC_CHECK_HEADERS(tcpd.h)
  # try using tcp wrappers without a library, with -lwrap and with -lwrap and -lnsl
  HAVE_LIBWRAP="yes"
  SAVE_LIBS="$LIBS"
  AC_MSG_CHECKING(for tcp wrapper functions)
  AC_LINK_IFELSE(
    [AC_LANG_PROGRAM([[int allow_severity,deny_severity;]],
                     [[request_init((void *)0,0);hosts_access((void *)0)]]) ],
    [AC_MSG_RESULT(yes)],
    [AC_MSG_RESULT(no)
     LIBS="-lwrap $LIBS"
     AC_MSG_CHECKING(for tcp wrapper functions in -lwrap)
     AC_LINK_IFELSE(
       [AC_LANG_PROGRAM([[int allow_severity,deny_severity;]],
                        [[request_init((void *)0,0);hosts_access((void *)0)]]) ],
       [AC_MSG_RESULT(yes)],
       [AC_MSG_RESULT(no)
        LIBS="-lnsl $LIBS"
        AC_MSG_CHECKING(for tcp wrapper functions in -lwrap -lnsl)
        AC_LINK_IFELSE(
          [AC_LANG_PROGRAM([[int allow_severity,deny_severity;]],
                           [[request_init((void *)0,0);hosts_access((void *)0)]]) ],
          [AC_MSG_RESULT(yes)],
          [AC_MSG_RESULT(no)
           LIBS="$SAVE_LIBS"
           HAVE_LIBWRAP="no"])
        ])
    ])
  if test "x$HAVE_LIBWRAP" != "xno"
  then
    AC_DEFINE_UNQUOTED(USE_LIBWRAP,1,[whether tcp wrappers are enabled])
  elif test "x$WANT_LIBWRAP" = "xyes"
  then
    AC_MSG_ERROR([*** tcp wrappers not found ***])
  fi
fi

# check wether we want use capabilities (yes,no,maybe)
WANT_CAPABILITIES="no"
AC_ARG_WITH(capabilities,
            AS_HELP_STRING([--with-capabilities],
                           [enable capabilities support (experimental)]),
            [if test "x$withval" = "xno"
             then
               WANT_CAPABILITIES="no"
             else
               WANT_CAPABILITIES="yes"
               # add supplied value to paths
               if test "x$withval" != "x" && test "x$withval" != "xyes"
               then
                 CPPFLAGS="-I$LIBWRAP/include $CPPFLAGS"
                 LDFLAGS="-L$LIBWRAP/lib $LDFLAGS"
               fi
             fi])

# check wether we can use capabilities
if test "x$WANT_CAPABILITIES" != "xno"
then
  HAVE_CAPABILITIES="yes"
  AC_CHECK_HEADERS(sys/capability.h,,HAVE_CAPABILITIES="no")
  AC_CHECK_HEADERS(sys/prctl.h,,HAVE_CAPABILITIES="no")
  AC_CHECK_TYPE(cap_t,,HAVE_CAPABILITIES="no",[
#include <sys/capability.h>])
  AC_SEARCH_LIBS(cap_init,cap,,HAVE_CAPABILITIES="no")
  AC_CHECK_FUNCS(prctl cap_from_text cap_to_text cap_get_proc cap_set_proc cap_free,,HAVE_CAPABILITIES="no")
  if test "x$HAVE_CAPABILITIES" != "xno"
  then
    AC_DEFINE_UNQUOTED(USE_CAPABILITIES,1,[Define to 1 if capabilities code will be enabled])
  elif test "x$WANT_CAPABILITIES" = "xyes"
  then
    AC_MSG_ERROR([*** capabilities not available ***])
  fi
fi

# where to find the configuration file
# TODO: this should probably be fixed to be nicer
CONFIGFILE=`eval echo $sysconfdir/cvsd/cvsd.conf | \
            sed "s%^NONE/%${prefix}/%" | \
            sed "s%^NONE/%${ac_default_prefix}/%"`
AC_SUBST(CONFIGFILE)
AC_DEFINE_UNQUOTED(DEFAULT_CONFIGFILE,"$CONFIGFILE",[location of the configuration file])
AC_MSG_NOTICE([using $CONFIGFILE as default location for configfile])

# where to find the binary (for init scripts)
CVSD_BIN=`eval echo $sbindir/cvsd | \
            sed "s%^NONE/%${exec_prefix}/%" | \
            sed "s%^NONE/%${prefix}/%" | \
            sed "s%^NONE/%${ac_default_prefix}/%"`
AC_SUBST(CVSD_BIN)

# store options passed to configure
CONFIGURE_CMD="$0 $ac_configure_args"
AC_SUBST(CONFIGURE_CMD)

# What files to output
AC_CONFIG_FILES(Makefile
                cvsd.8 cvsd-buildroot.8 cvsd-passwd.8 cvsd.conf.5
                cvsd-buginfo.8
                cvsd.spec)
AC_CONFIG_FILES(cvsd-buildroot,chmod a+rx cvsd-buildroot)
AC_CONFIG_FILES(cvsd-passwd,chmod a+rx cvsd-passwd)
AC_CONFIG_FILES(cvsd-buginfo,chmod a+rx cvsd-buginfo)
AC_CONFIG_FILES(cvsd.init,chmod a+rx cvsd.init)
AC_CONFIG_FILES(cvsd.init.redhat71,chmod a+rx cvsd.init.redhat71)
AC_OUTPUT

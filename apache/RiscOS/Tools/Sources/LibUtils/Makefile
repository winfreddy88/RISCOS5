# Makefile for LibUtils transient
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name   Description
# ----           ----   -----------
# 09-Mar-2011    SAR    Created
#

#
# Program specific options:
#
COMPONENT ?= MUST_SPECIFY_COMPONENT
UTILITY    = util.${COMPONENT}
LIB_EX_DIR = <Lib$Dir>.${COMPONENT}

CHMODFLAGS = -R 0755

include Makefiles:StdTools

#
# Objects
#
OBJS       = o.${COMPONENT}

#
# Rule patterns
#
.s.o:;     ${AS} ${OFLAGS} -o $@ $<

#
# Default rule
#
all: ${UTILITY}
        @echo ${COMPONENT}: all complete

#
# RISC OS ROM build rules:
#
clean:
        ${XWIPE} util ${WFLAGS}
        ${XWIPE} o    ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#
# RISC OS disc build rules:
#
install: ${UTILITY}
        ${MKDIR} ${INSTDIR}
        ${CP} ${UTILITY} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        ${CHMOD} ${CHMODFLAGS} ${INSTDIR}
        @echo ${COMPONENT}: installed to ${INSTDIR}

#
# Other rules:
#
${UTILITY}: ${OBJS} dirs
        ${LD} -o $@ -bin ${OBJS}
        SetType $@ Utility
        ${CHMOD} ${CHMODFLAGS} $@

dirs:
        ${MKDIR} util
        ${MKDIR} o

#---------------------------------------------------------------------------
# Dynamic dependencies:

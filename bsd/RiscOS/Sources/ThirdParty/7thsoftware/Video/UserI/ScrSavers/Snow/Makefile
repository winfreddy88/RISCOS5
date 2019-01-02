# Makefile for !Snow
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date         Name  Description
# ----         ----  -----------
# 09 Jan 2010  SAR   Created from !Routines makefile
#

COMPONENT ?= Snow
TARGET    ?= !${COMPONENT}
INSTDIR   ?= <Install$Dir>
INSTAPP    = ${INSTDIR}.${TARGET}

CHMODFLAGS = -R 0755

include Makefiles:StdTools

clean:
	@echo Component '${COMPONENT}': $@

install:
	${MKDIR} ${INSTAPP}
	${CP} BAS.!RunImage ${INSTAPP}.!RunImage ${CPFLAGS}
	${CP} Resources     ${INSTAPP}           ${CPFLAGS}
	${AWK} -f Build:AwkVers Resources.Messages > ${INSTAPP}.Messages
	${CHMOD} ${CHMODFLAGS} ${INSTAPP}
	@echo Component '${COMPONENT}': $@ (disc build)

# Dynamic dependencies:

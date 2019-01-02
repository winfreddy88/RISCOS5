# Makefile for !Random
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date         Name  Description
# ----         ----  -----------
# 09 Jan 2010  SAR   Created from !Routines makefile
#

COMPONENT ?= Random
TARGET    ?= !${COMPONENT}
INSTDIR   ?= <Install$Dir>
INSTAPP    = ${INSTDIR}.${TARGET}
INSTSETUP  = ${INSTAPP}.!SvrSetup

CHMODFLAGS = -R 0755

include Makefiles:StdTools

clean:
	@echo Component '${COMPONENT}': $@

install:
	${MKDIR} ${INSTSETUP}
	${CP} BAS.!RunImage   ${INSTAPP}.!RunImage   ${CPFLAGS}
	${CP} BAS.SvrImage    ${INSTSETUP}.!RunImage ${CPFLAGS}
	${CP} BAS.RandomLib   ${INSTSETUP}.RandomLib ${CPFLAGS}
	${CP} Resources.Saver ${INSTAPP}             ${CPFLAGS}
	${CP} Resources.Setup ${INSTSETUP}           ${CPFLAGS}
	${AWK} -f Build:AwkVers Resources.Saver.Messages > ${INSTAPP}.Messages
	${AWK} -f Build:AwkVers Resources.Setup.Messages > ${INSTSETUP}.Messages
	${CHMOD} ${CHMODFLAGS} ${INSTAPP}
	@echo Component '${COMPONENT}': $@ (disc build)

# Dynamic dependencies:

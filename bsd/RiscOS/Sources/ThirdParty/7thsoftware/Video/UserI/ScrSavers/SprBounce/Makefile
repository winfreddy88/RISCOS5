# Makefile for !SprBounce
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date         Name  Description
# ----         ----  -----------
# 04 Feb 2010  SAR   Created from !Random screensaver makefile
#

COMPONENT ?= SprBounce
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
	${CP} BAS.SetupLib    ${INSTSETUP}.SetupLib  ${CPFLAGS}
	${CP} Resources.Saver ${INSTAPP}             ${CPFLAGS}
	${CP} Resources.Setup ${INSTSETUP}           ${CPFLAGS}
	${AWK} -f Build:AwkVers Resources.Saver.Messages > ${INSTAPP}.Messages
	${AWK} -f Build:AwkVers Resources.Setup.Messages > ${INSTSETUP}.Messages
	${CHMOD} ${CHMODFLAGS} ${INSTAPP}
	@echo Component '${COMPONENT}': $@ (disc build)

# Dynamic dependencies:

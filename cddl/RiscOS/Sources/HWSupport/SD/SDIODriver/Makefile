# Makefile for SDIODriver

COMPONENT   = SDIODriver
ASMHDRS     = SDIO SDHCIDevice
ASMCHDRS    = SDIO SDHCIDevice
HDRS        =
CMHGFILE    = SDIOHdr
CMHGDEPENDS = device module swi
OBJS        = cardreg command device fgopcb globals message module op probe register stuff swi trampoline util
LIBS        = ${SYNCLIB}
ROMCDEFINES = -DROM_MODULE

# Enable one of the following groups, depending on what sort of debug you want

#CFLAGS     += -DDEBUG_ENABLED

#CFLAGS     += -DDEBUG_ENABLED -DDEBUGLIB -DDEBUGLIB_NOBRACKETS
#LIBS       += ${DEBUGLIBS} ${NET5LIBS}

#OBJS       += gpiodebug
#CFLAGS     += -DGPIODEBUG

include CModule

expasmc.SDHCIDevice: hdr.SDHCIDevice h.SDHCIDevice
	${HDR2H} hdr.SDHCIDevice ${C_EXP_HDR}.SDHCIDevice
	FAppend ${C_EXP_HDR}.SDHCIDevice h.SDHCIDevice ${C_EXP_HDR}.SDHCIDevice

# Dynamic dependencies:

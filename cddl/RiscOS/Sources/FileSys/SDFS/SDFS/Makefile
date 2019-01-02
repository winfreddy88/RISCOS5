# Makefile for SDFS

COMPONENT   = SDFS
ASMHDRS     = SDFS SDFSErr
ASMCHDRS    = SDFS SDFSErr
HDRS        =
CMHGFILE    = SDFSHdr
CMHGDEPENDS = command module
OBJS        = base cardreg command discop free freeveneer globals message miscop module sdio service swi
LIBS        = ${SYNCLIB}
ROMCDEFINES = -DROM_MODULE
CLEAN_DEPEND = extra_clean

#CFLAGS     += -DDEBUG_ENABLED

#OBJS       += gpiodebug
#CFLAGS     += -DGPIODEBUG

include CModule

expasmc.SDFSErr: hdr.SDFSErr
	${HDR2H} hdr.SDFSErr ${C_EXP_HDR}.SDFSErr
	
expasm.SDFSErr: hdr.SDFSErr
	${CP} hdr.SDFSErr ${EXP_HDR}.SDFSErr ${CPFLAGS}

hdr.SDFSErr: o.SDFSErr
	${LD} -bin -o $@ o.SDFSErr
	SetType $@ Text

ifeq (,${MAKE_VERSION})

# RISC OS / amu case

clean::
	@IfThere hdr.SDFSErr Then ${ECHO} ${RM} hdr.SDFSErr
	@IfThere hdr.SDFSErr Then ${RM} hdr.SDFSErr

else

# Posix / gmake case

clean::
	${NOP}

endif

# Dynamic dependencies:

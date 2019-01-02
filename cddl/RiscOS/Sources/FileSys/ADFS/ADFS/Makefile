# Makefile for ADFS

COMPONENT   = ADFS
ASMHDRS     = ADFS ADFSErr
ASMCHDRS    = ADFS ADFSErr
HDRS        =
CMHGFILE    = ADFSHdr
CMHGDEPENDS = command module
OBJS        = ata base command discop drive globals message miscop module swi
LIBS        = ${SYNCLIB}
ROMCDEFINES = -DROM_MODULE
CLEAN_DEPEND = extra_clean

#CFLAGS     += -DDEBUG_ENABLED

#CFLAGS     += -DDEBUG_ENABLED -DDEBUGLIB -DDEBUGLIB_NOBRACKETS
#LIBS       += ${DEBUGLIBS} ${NET5LIBS}

include CModule

expasmc.ADFSErr: hdr.ADFSErr
	${HDR2H} hdr.ADFSErr ${C_EXP_HDR}.ADFSErr
	
expasm.ADFSErr: hdr.ADFSErr
	${CP} hdr.ADFSErr ${EXP_HDR}.ADFSErr ${CPFLAGS}

hdr.ADFSErr: o.ADFSErr
	${LD} -bin -o $@ o.ADFSErr
	SetType $@ Text

ifeq (,${MAKE_VERSION})

# RISC OS / amu case

clean::
	@IfThere hdr.ADFSErr Then ${ECHO} ${RM} hdr.ADFSErr
	@IfThere hdr.ADFSErr Then ${RM} hdr.ADFSErr

else

# Posix / gmake case

clean::
	${NOP}

endif

# Dynamic dependencies:

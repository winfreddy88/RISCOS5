# Makefile for BootFX
#

COMPONENT   = BootFX
CMHGAUTOHDR = ${TARGET}
CMHGDEPENDS = bootfx
OBJS        = bootfx
ROMCDEFINES = -DROM_MODULE
INSTRES_FILES   = 1920x1080 Logo Bar24
INSTRES_DEPENDS = Bar24

include CModule

# Pass the current UserIF through to the C code
CFLAGS += -DUserIF_${USERIF}

# Squash the boot screen sprite for this UserIF for install into ResourceFS
Bar24: LocalUserIFRes:BarSprite
        ${SQUASH} LocalUserIFRes:BarSprite Resources${SEP}Bar24

clean::
        ${RM} Resources${SEP}Bar24

# Dynamic dependencies:

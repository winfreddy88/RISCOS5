# Makefile for BootCommands
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name       Description
# ----           ----       -----------
# 26 Nov 2011    TM         Created.
#

#
# Generic options:
#
MKDIR   = do mkdir -p
CP      = copy
CPFLAGS = ~cfr~v
WIPE    = -wipe
XWIPE   = x wipe
WFLAGS  = ~c~vr
RM      = remove

#
# Program specific options:
#
COMPONENT = COMCentre
APP        = !COMCentre
RDIR       = Resources

#
# Export Paths for Messages module
#
RESDIR = <resource$dir>.Resources.${COMPONENT}

#
# Libraries:
#

FILES =\
 ${RDIR}.*

#
# Generic rules {used by top-level build}:
#

# Silly NAS effects. Without the Apps creation
# Samba creates an error
install:
        ${XWIPE} ${INSTDIR} ${WFLAGS}
        ${MKDIR} ${INSTDIR}
        ${MKDIR} ${INSTDIR}.Apps
        $(CP) $(RDIR).*  ${INSTDIR}.*    ${CPFLAGS}
        -Access ${INSTDIR}.*             lr/r
        @echo ${COMPONENT}: Application installed (Disc)

#Internal targets

#General rules

# Dynamic dependencies:

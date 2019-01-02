# Makefile for USBDevSwp
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name       Description
# ----           ----       -----------
# 5  Jun 2011    TM         Created.
# 26 Nov 2011    TM         Corrected
#

#
# Generic options:
#
MKDIR   = do mkdir -p
# tbox must be located before C or there will be troubles
CC      = cc -Itbox:,C: -fach -wp
CP      = copy
CPFLAGS = ~cfr~v
OBJASM  = ObjAsm ${THROWBACK} -depend !Depend -stamp -quit
CMHG    = CMHG -IC:
LINK    = Link 
ZM      = -zM
WIPE    = -wipe
XWIPE   = x wipe
WFLAGS  = ~c~vr
RM      = remove

STUBS   = CLib:o.Stubs

#
# Program specific options:
#

COMPONENT = USBDevSwp
APP        = !USBDevSwp
MODULE     = rm.${COMPONENT}
RDIR       = Resources

#
# Export Paths
#

RESDIR = <resource$dir>.Resources.${APP}

#
# Libraries:
#

OBJS = o.usbdevswphead o.usbdevswpmodule
OBJSA = o.usbdevswp

FILES =\
 !RunImage\
 ${RDIR}.*\
 RM.USBDevSwp

#
# Generic rules {used by top-level build}:
#

all: rm.${COMPONENT} !Runimage

install: ${FILES}
        ${XWIPE} ${INSTDIR} ${WFLAGS}
        ${MKDIR} ${INSTDIR}
        ${MKDIR} ${INSTDIR}.Devices
        $(CP) ${RDIR}.*      ${INSTDIR}.* ${CPFLAGS}
        $(CP) RM.USBDevSwp   ${INSTDIR}.USBDevSwp ${CPFLAGS}
        $(CP) !RunImage      ${INSTDIR}.!RunImage ${CPFLAGS}
        -Access ${INSTDIR}.*             lr/r
        @echo ${COMPONENT}: Application installed (Disc)

clean:
        ${XWIPE} !Runimage ${WFLAGS}
        ${XWIPE} o.* ${WFLAGS}
        ${XWIPE} rm.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#Internal targets
RM.USBDevSwp: ${OBJS} ${OSLIB} ${STUBS}
   ${LINK} -rmf -output RM.USBDevSwp ${OBJS} ${OSLIB} ${STUBS}
   Access RM.USBDevSwp WR/R

!Runimage: ${OBJSA} ${OSLIB} ${STUBS}
   ${LINK} -aif -output !Runimage ${OBJSA} ${OSLIB} ${STUBS} <tbox$path>o.eventlib \
            <tbox$path>o.toolboxlib <tbox$path>o.wimplib 
   Access !Runimage WR/R

#General rules

# The c o mapping is a dream: A little nightmare. Depending on the source
# module compilation is switched on or off

.SUFFIXES:   .cmhg .c .debug .o .asm .def
.c.o:;       ${CC} ${THROWBACK} -depend !Depend -c $(if $(findstring usbdevswpmodule,$<), ${ZM}) -ff $<
.asm.o:;     ${OBJASM} -stamp -quit $< $@
.asm.debug:; ${OBJASM} -pd "TRACE SETL {TRUE}" -pd "STANDALONE SETL {TRUE}" -stamp -quit $< $@
.c.debug:;   ${CC} ${THROWBACK} -depend !Depend -c ${ZM} -ff -DTRACE=1 -DSTANDALONE -o $@ $<
.cmhg.o:;    ${CMHG} -p -depend !Depend $< $@
.c.s:;       ${CC} ${THROWBACK} -depend !Depend -s ${ZM} -ff $<
.def.o:;     DefMod -l -o l.$* < $<
             LibFile -c -o $@ -via ViaFile
             Wipe l.$* ~C~FR~V
.def.h:;     DefMod -h < $< > $@
.def.s:;     DefMod -s < $< > $@

# Dynamic dependencies:
o.usbdevswphead:	cmhg.usbdevswphead
o.usbdevswphead:	cmhg.^.VersionNum
o.usbdevswpmodule:	c.usbdevswpmodule
o.usbdevswpmodule:	C:h.kernel
o.usbdevswpmodule:	C:h.swis
o.usbdevswpmodule:	h.usbdevswphead
o.usbdevswpmodule:	h.error
o.usbdevswpmodule:	C:h.kernel
o.usbdevswpmodule:	C:h.swis
o.usbdevswpmodule:	h.configuration
o.usbdevswpmodule:	C:h.kernel
o.usbdevswpmodule:	C:h.swis
o.usbdevswpmodule:	h.error
o.usbdevswp:	c.usbdevswp
o.usbdevswp:	tbox:h.event
o.usbdevswp:	tbox:h.wimp
o.usbdevswp:	tbox:h.toolbox
o.usbdevswp:	C:h.kernel
o.usbdevswp:	tbox:h.toolbox
o.usbdevswp:	tbox:h.wimp
o.usbdevswp:	tbox:h.wimplib
o.usbdevswp:	tbox:h.menu
o.usbdevswp:	tbox:h.gadgets
o.usbdevswp:	tbox:h.proginfo
o.usbdevswp:	tbox:h.window
o.usbdevswp:	tbox:h.dcs
o.usbdevswp:	tbox:h.window
o.usbdevswp:	C:h.kernel
o.usbdevswp:	C:h.swis
o.usbdevswp:	h.configuration
o.usbdevswp:	C:h.kernel
o.usbdevswp:	C:h.swis
o.usbdevswp:	h.error
o.usbdevswp:	C:h.kernel
o.usbdevswp:	C:h.swis
o.usbdevswp:	h.tb_defs

# Makefile for BootCommands
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name       Description
# ----           ----       -----------
# 5 Oct 2010     TM         Created.
#

#
# Generic options:
#
MKDIR   = do mkdir -p
CC      = cc -IC:,OSLib:,USBLib: -fach -wp
CP      = copy
CPFLAGS = ~cfr~v
OBJASM  = ObjAsm ${THROWBACK} -depend !Depend -stamp -quit
CMHG    = CMHG -IC:,OSLiB:,USBLib: -d $(subst .o.,.h.,@.o.ftdimodhead)
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
COMPONENT = FTDI
APP        = !FTDI
MODULE     = rm.${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}

#
# Export Paths for Messages module
#
RESDIR = <resource$dir>.Resources.${COMPONENT}
RESAPP = <resource$dir>.Apps.${APP}

#
# Libraries:
#
OSLIB  = OSLib:OSLib.o
USBLib = USBLib:USBLIB.o

FILES =\
 Docs.Manual.*\
 ${RDIR}.!Boot\
 ${RDIR}.!Help\
 ${RDIR}.!Run\
 ${RDIR}.Devices.*\
 ${RDIR}.Help\
 ${RDIR}.NewDevs\
 ${RDIR}.SetAlias\
 ${RDIR}.StrtSmDevs\
 $(LDIR).*\
 RM.FTDI

OBJS = o.error o.ftdi o.configuration o.serial \
       o.upcall o.ftdimodule o.callback o.debug \
       o.driver o.command o.ftdimodhead

#
# Generic rules {used by top-level build}:
#

all: rm.${COMPONENT}

install: ${FILES}
        ${MKDIR} ${INSTDIR}
        ${MKDIR} ${INSTDIR}.Docs.Manual
        ${MKDIR} ${INSTDIR}.Devices
        ${MKDIR} ${INSTDIR}.$(LDIR)
        $(CP) Docs.Manual.*      ${INSTDIR}.Docs.Manual.* ${CPFLAGS}
        $(CP) $(RDIR).!Boot      ${INSTDIR}.!Boot         ${CPFLAGS}
        $(CP) $(RDIR).!Help      ${INSTDIR}.!Help         ${CPFLAGS}
        $(CP) $(RDIR).!Run       ${INSTDIR}.!Run          ${CPFLAGS}
        $(CP) $(RDIR).Devices.*  ${INSTDIR}.Devices.*     ${CPFLAGS}
        $(CP) $(RDIR).Help       ${INSTDIR}.Help          ${CPFLAGS}
        $(CP) $(RDIR).NewDevs    ${INSTDIR}.NewDevs       ${CPFLAGS}
        $(CP) $(RDIR).SetAlias   ${INSTDIR}.SetAlias      ${CPFLAGS}
        $(CP) $(RDIR).StrtSmDevs ${INSTDIR}.StrtSmDevs    ${CPFLAGS}
        $(CP) $(LDIR).*          ${INSTDIR}.$(LDIR).*     ${CPFLAGS}
        $(CP) RM.FTDI            ${INSTDIR}.FTDI          ${CPFLAGS}
        -Access ${INSTDIR}.Docs.Manual.* lr/r
        -Access ${INSTDIR}.!Boot         lr/r
        -Access ${INSTDIR}.!Help         lr/r
        -Access ${INSTDIR}.!Run          lr/r
        -Access ${INSTDIR}.Devices.*     lr/r
        -Access ${INSTDIR}.FTDI          lr/r
        -Access ${INSTDIR}.Help          lr/r
        -Access ${INSTDIR}.NewDevs       lr/r
        -Access ${INSTDIR}.SetAlias      lr/r
        -Access ${INSTDIR}.StrtSmDevs    lr/r
        -Access ${INSTDIR}.$(LDIR).*     lr/r
        @echo ${COMPONENT}: Application installed (Disc)

clean:
        ${XWIPE} o.* ${WFLAGS}
        ${XWIPE} rm.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#Internal targets
RM.FTDI: ${OBJS} ${OSLIB} ${STUBS}
   ${LINK} -rmf -output RM.FTDI ${OBJS} ${OSLIB} ${STUBS}
   Access RM.FTDI WR/R

#General rules
.SUFFIXES:   .cmhg .c .debug .o .asm .def
.c.o:;       ${CC} ${THROWBACK} -depend !Depend -c ${ZM} -ff $<
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
o.error:	c.error
o.error:	C:h.kernel
o.error:	C:h.swis
o.error:	h.error
o.error:	C:h.kernel
o.ftdi:	c.ftdi
o.ftdi:	C:h.kernel
o.ftdi:	C:h.swis
o.ftdi:	h.ftdi
o.configuration:	c.configuration
o.configuration:	h.configuration
o.configuration:	h.ftdi
o.serial:	c.serial
o.serial:	h.error
o.serial:	C:h.kernel
o.serial:	h.configuration
o.serial:	h.serial
o.serial:	C:h.kernel
o.serial:	h.ftdi
o.upcall:	c.upcall
o.upcall:	C:h.kernel
o.upcall:	h.upcall
o.upcall:	h.error
o.upcall:	C:h.kernel
o.ftdimodule:	c.ftdimodule
o.ftdimodule:	C:h.kernel
o.ftdimodule:	C:h.swis
o.ftdimodule:	USBLib:h.USBDevFS
o.ftdimodule:	h.error
o.ftdimodule:	C:h.kernel
o.ftdimodule:	h.configuration
o.ftdimodule:	h.serial
o.ftdimodule:	C:h.kernel
o.ftdimodule:	h.ftdi
o.ftdimodule:	h.callback
o.ftdimodule:	h.ftdimodule
o.ftdimodule:	OSLib:oslib.h.devicefs
o.ftdimodule:	OSLib:oslib.h.types
o.ftdimodule:	OSLib:oslib.h.os
o.ftdimodule:	OSLib:oslib.h.oscore32
o.ftdimodule:	OSLib:oslib.h.osf32
o.ftdimodule:	OSLib:oslib.h.osargs
o.ftdimodule:	OSLib:oslib.h.fileswitch
o.ftdimodule:	OSLib:oslib.h.fileswch32
o.ftdimodule:	OSLib:oslib.h.osargs32
o.ftdimodule:	OSLib:oslib.h.buffer
o.ftdimodule:	OSLib:oslib.h.devicefs32
o.ftdimodule:	h.upcall
o.ftdimodule:	h.error
o.ftdimodule:	h.ftdi
o.ftdimodule:	h.driver
o.ftdimodule:	h.ftdimodhead
o.ftdimodule:	h.ftdimodule
o.ftdimodule:	h.callback
o.callback:	c.callback
o.callback:	C:h.kernel
o.callback:	C:h.swis
o.callback:	h.ftdimodhead
o.callback:	h.callback
o.callback:	h.ftdimodule
o.callback:	OSLib:oslib.h.devicefs
o.callback:	OSLib:oslib.h.types
o.callback:	OSLib:oslib.h.os
o.callback:	OSLib:oslib.h.oscore32
o.callback:	OSLib:oslib.h.osf32
o.callback:	OSLib:oslib.h.osargs
o.callback:	OSLib:oslib.h.fileswitch
o.callback:	OSLib:oslib.h.fileswch32
o.callback:	OSLib:oslib.h.osargs32
o.callback:	OSLib:oslib.h.buffer
o.callback:	OSLib:oslib.h.devicefs32
o.callback:	h.upcall
o.callback:	h.error
o.callback:	C:h.kernel
o.callback:	h.ftdi
o.debug:	c.debug
o.debug:	h.debug
o.debug:	C:h.kernel
o.debug:	h.ftdimodhead
o.driver:	c.driver
o.driver:	USBLib:h.USBDevFS
o.driver:	h.error
o.driver:	C:h.kernel
o.driver:	h.serial
o.driver:	C:h.kernel
o.driver:	h.ftdi
o.driver:	h.callback
o.driver:	h.ftdimodule
o.driver:	OSLib:oslib.h.devicefs
o.driver:	OSLib:oslib.h.types
o.driver:	OSLib:oslib.h.os
o.driver:	OSLib:oslib.h.oscore32
o.driver:	OSLib:oslib.h.osf32
o.driver:	OSLib:oslib.h.osargs
o.driver:	OSLib:oslib.h.fileswitch
o.driver:	OSLib:oslib.h.fileswch32
o.driver:	OSLib:oslib.h.osargs32
o.driver:	OSLib:oslib.h.buffer
o.driver:	OSLib:oslib.h.devicefs32
o.driver:	h.upcall
o.driver:	h.error
o.driver:	h.ftdi
o.driver:	h.driver
o.command:	c.command
o.command:	C:h.kernel
o.command:	C:h.swis
o.command:	h.ftdimodhead
o.command:	h.ftdimodule
o.command:	OSLib:oslib.h.devicefs
o.command:	OSLib:oslib.h.types
o.command:	OSLib:oslib.h.os
o.command:	OSLib:oslib.h.oscore32
o.command:	OSLib:oslib.h.osf32
o.command:	OSLib:oslib.h.osargs
o.command:	OSLib:oslib.h.fileswitch
o.command:	OSLib:oslib.h.fileswch32
o.command:	OSLib:oslib.h.osargs32
o.command:	OSLib:oslib.h.buffer
o.command:	OSLib:oslib.h.devicefs32
o.command:	h.upcall
o.command:	h.error
o.command:	C:h.kernel
o.command:	h.ftdi
o.ftdimodhead:	cmhg.ftdimodhead
o.ftdimodhead:	OSLiB:oslib.h.devicefs
o.ftdimodhead:	OSLiB:oslib.h.types
o.ftdimodhead:	OSLiB:oslib.h.os
o.ftdimodhead:	OSLiB:oslib.h.oscore32
o.ftdimodhead:	OSLiB:oslib.h.osf32
o.ftdimodhead:	OSLiB:oslib.h.osargs
o.ftdimodhead:	OSLiB:oslib.h.fileswitch
o.ftdimodhead:	OSLiB:oslib.h.fileswch32
o.ftdimodhead:	OSLiB:oslib.h.osargs32
o.ftdimodhead:	OSLiB:oslib.h.buffer
o.ftdimodhead:	OSLiB:oslib.h.devicefs32
o.ftdimodhead:	USBLib:h.USBDevFS
o.ftdimodhead:	cmhg.^.VersionNum

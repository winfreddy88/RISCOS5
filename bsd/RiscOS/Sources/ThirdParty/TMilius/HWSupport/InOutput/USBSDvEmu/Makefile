# Makefile for BootCommands
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name       Description
# ----           ----       -----------
# 26 Nov 2010    TM         Created.
#

#
# Generic options:
#
MKDIR   = do mkdir -p
CC      = cc -IC:,OSLib:,USBLib: -fach -wp
CP      = copy
CPFLAGS = ~cfr~v
OBJASM  = ObjAsm ${THROWBACK} -depend !Depend -stamp -quit
CMHG    = CMHG -IC:,OSLiB:,USBLib:
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
COMPONENT = USBSDvEmu
MODULE     = rm.${COMPONENT}
LDIR       = ${RDIR}.${LOCALE}

#
# Export Paths for Messages module
#

#
# Libraries:
#

OBJS = o.usbsdvemuhead o.usbsdvemumodule

#
# Generic rules {used by top-level build}:
#

all: rm.${COMPONENT}

clean:
        ${XWIPE} o.* ${WFLAGS}
        ${XWIPE} rm.* ${WFLAGS}
        @echo ${COMPONENT}: cleaned

#Internal targets
RM.USBSDvEmu: ${OBJS} ${OSLIB} ${STUBS}
   ${LINK} -rmf -output RM.USBSDvEmu ${OBJS} ${OSLIB} ${STUBS}
   Access RM.USBSDvEmu WR/R

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
o.usbsdvemuhead:	cmhg.usbsdvemuhead
o.usbsdvemuhead:	cmhg.^.Version
o.usbsdvemumodule:	c.usbsdvemumodule
o.usbsdvemumodule:	C:h.kernel
o.usbsdvemumodule:	C:h.swis
o.usbsdvemumodule:	h.usbsdvemuhead

# Makefile for TchScrn
#
# Copyright (c) 2008 by Thomas Milius Stade, Germany
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 10-Feb-08  TM     Created

#
# Program specific options:
#
COMPONENT   = TchScrn
APP         = !TchScrn
MODULE      = rm.${COMPONENT}
RDIR        = Resources
INSTDIR    ?= INSTDIR=<Install$Dir>.HardDisc4.!Boot.Resources
DOCDIR      = Docs

#
# Generic options:
#
include Makefiles:StdTools

MV          = rename
DOXYGEN     = doxygen

CFLAGSM     = ${THROWBACK} -depend !Depend ${INCLUDESM} -g -zM
#CFLAGSM     = ${THROWBACK} -depend !Depend ${INCLUDESM} -g -DUSE_SYSLOG -zM
CFLAGSC     = ${THROWBACK} -depend !Depend ${INCLUDESC} -g

#CMHGFLAGS   = -DUSE_SYSLOG
CMHGFLAGS   =

#
# Libraries
#
CLIB        = CLib:o.stubs
EVENTLIB    = tbox:o.eventlib
TOOLBOXLIB  = tbox:o.toolboxlib
WIMPLIB     = tbox:o.wimplib
RENDERLIB   = tbox:o.renderlib

#
# Include files
#
INCLUDESM   = -IC:
INCLUDESC   = -Itbox:,RISC_OSLib:,C:

FILES =\
  ${RDIR}.!Boot \
  ${RDIR}.!Help \
  ${RDIR}.!Run \
  ${RDIR}.!Sprites \
  ${RDIR}.Cross \
  ${MODULE} \
  ${RDIR}.!RunImage

OBJSM =\
  om.tchscrn \
  oh.tchscrn_adapt
#  debug.syslog32

OBJSC =\
  o.calibration


#
# Rule patterns
#
.SUFFIXES: .o .om .oh
.c.o:;    ${CC} ${CFLAGSC} -c -ff $<
.c.om:;    ${CC} ${CFLAGSM} -o $@ -c -ff $<
.cmhg.oh:;    cmhg ${CMHGFLAGS} -p -o $@ $<

#
# Main rules:
#
all: ${FILES} dirs
        @echo ${COMPONENT}: built {All}

install: all
        @echo
        @echo ${COMPONENT}: Creating application ${APP}
        ${XWIPE} ${INSTDIR}.${APP} ${WFLAGS}
        ${MKDIR} ${INSTDIR}.${APP}
        ${CP} ${RDIR}                             ${INSTDIR}.${APP}         ${CPFLAGS}
        ${CP} ${RDIR}.UK                          ${INSTDIR}.${APP}         ${CPFLAGS}
        ${CP} ${RDIR}.Germany                     ${INSTDIR}.${APP}         ${CPFLAGS}
        ${CP} ${MODULE}                           ${INSTDIR}.${APP}.TchScrn ${CPFLAGS}
        ${CP} ${DOCDIR}.Manual.specification/html ${INSTDIR}.${APP}.Docs.specification/html   ${CPFLAGS}
        ${MV} ${INSTDIR}.${APP}.Germany.Messages7 ${INSTDIR}.${APP}.Messages35
        ${MV} ${INSTDIR}.${APP}.Germany.Res7      ${INSTDIR}.${APP}.Res35
        ${XWIPE} ${INSTDIR}.${APP}.UK         ${WFLAGS}
        ${XWIPE} ${INSTDIR}.${APP}.Germany    ${WFLAGS}
        ${XWIPE} ${INSTDIR}.${APP}.DevSupport ${WFLAGS}
        Access ${INSTDIR}.${APP}.* wr/r
        @echo
        @echo ${COMPONENT}: Application installed {Disc}

dirs:
        ${MKDIR} o
        ${MKDIR} oh
        ${MKDIR} om
        ${MKDIR} rm

clean:
        ${XWIPE} rm                ${WFLAGS}
        ${XWIPE} o                 ${WFLAGS}
        ${XWIPE} oh                ${WFLAGS}
        ${XWIPE} om                ${WFLAGS}
        ${XWIPE} Docs.Doxygen.*    ${WFLAGS}
        ${XWIPE} ${INSTDIR}.${APP} ${WFLAGS}
        ${RM} ${RDIR}.!RunImage
        @echo ${COMPONENT}: cleaned

docu:
        ${MKDIR} Docs.Doxygen.Calibration
        ${MKDIR} Docs.Doxygen.Driver
        @${DOXYGEN} DoxyFileDriver
        @${DOXYGEN} DoxyFileCalib
        @echo ${COMPONENT}: documentation generated

#
# Static dependencies:
#
${MODULE}: ${OBJSM} ${CLIB}
       ${LD} -rmf -c++ -o $@ ${OBJSM} ${CLIB}

Resources.!RunImage: ${OBJSC} ${EVENTLIB} ${TOOLBOXLIB} ${WIMPLIB} ${RENDERLIB} ${CLIB}
       ${LD} -aif -c++ -o $@ ${OBJSC} ${CLIB} ${EVENTLIB} ${TOOLBOXLIB} ${WIMPLIB} ${RENDERLIB}


#Resources.!RunImage: ${OBJSC} ${EVENTLIB} ${TOOLBOXLIB} ${WIMPLIB} ${RENDERLIB} ${CLIB}
#       ${LD} -aif -DEBUG -c++ -o $@ ${OBJSC} ${CLIB} ${EVENTLIB} ${TOOLBOXLIB} ${WIMPLIB} ${RENDERLIB}


#---------------------------------------------------------------------------
# Dynamic dependencies:
om.tchscrn:	c.tchscrn
om.tchscrn:	C:h.kernel
om.tchscrn:	C:h.swis
om.tchscrn:	h.common
om.tchscrn:	h.usb
om.tchscrn:	C:h.kernel
om.tchscrn:	C:h.swis
om.tchscrn:	h.common_mod
om.tchscrn:	h.common
om.tchscrn:	h.rpi_disp7
om.tchscrn:	C:h.kernel
om.tchscrn:	C:h.swis
om.tchscrn:	h.common_mod
o.calibration:	c.calibration
o.calibration:	tbox:h.event
o.calibration:	tbox:h.wimp
o.calibration:	tbox:h.toolbox
o.calibration:	C:h.kernel
o.calibration:	tbox:h.toolbox
o.calibration:	tbox:h.wimp
o.calibration:	tbox:h.wimplib
o.calibration:	tbox:h.menu
o.calibration:	tbox:h.gadgets
o.calibration:	tbox:h.proginfo
o.calibration:	tbox:h.window
o.calibration:	tbox:h.dcs
o.calibration:	tbox:h.window
o.calibration:	tbox:h.drawfile
o.calibration:	C:h.kernel
o.calibration:	C:h.swis
o.calibration:	h.common
o.calibration:	h.tb_defs
o.calibration:	h.draw
o.calibration:	tbox:h.wimplib
o.calibration:	tbox:h.drawfile
o.calibration:	RISC_OSLib:h.drawfobj
o.calibration:	RISC_OSLib:h.drawfdiag
o.calibration:	RISC_OSLib:h.os
o.calibration:	RISC_OSLib:h.drawftypes
o.calibration:	RISC_OSLib:h.sprite

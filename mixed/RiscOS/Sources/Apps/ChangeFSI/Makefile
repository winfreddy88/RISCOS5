# Copyright 1996 Acorn Computers Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Makefile for ChangeFSI
#

#
# Program specific options:
#
COMPONENT  = ChangeFSI
APP        = !ChangeFSI
DDIR       = DataFiles
LDIR       = ${LOCALE}
SDIR       = source
CFSIDIR    = ${INSTDIR}.${APP}
VPATH      = @ JPEG hpcdtoppm btpc
MSGS       = ${DDIR}.Messages

include StdTools
include StdRules
include AppLibs

#
# Tool flags:
#
DFLAGS  = -DDEFAULT_MAX_MEM=655360 -DRISCOS_TWEAK
CFLAGS  = -IC: -c -depend !Depend ${INCLUDES} ${DFLAGS}
C++FLAGS= -IC: -c -depend !Depend ${INCLUDES} ${DFLAGS} -Xcc -ff

INCLUDES = 

FILES  =\
 ${LDIR}.!Help\
 ${LDIR}.!Run\
 ${DDIR}.!Boot\
 ${DDIR}.!Sprites\
 ${DDIR}.!Sprites11\
 ${DDIR}.!Sprites22\
 ${DDIR}.Documents.256sprites\
 ${DDIR}.Documents.CmdBasUse\
 ${DDIR}.Documents.DesktopUse\
 ${DDIR}.Documents.Formats\
 ${DDIR}.Documents.JPEGInfo\
 ${DDIR}.Documents.BTPCInfo\
 ${DDIR}.Documents.Theory\
 ${DDIR}.Palettes.Palette2\
 ${DDIR}.Palettes.Palette4\
 ${DDIR}.Palettes.Palette64\
 ${DDIR}.Palettes.Palette16\
 ${DDIR}.Palettes.Palette256\
 ${DDIR}.Palettes.CFSIict\
 ${DDIR}.btpc.btpc\
 ${DDIR}.btpc.HourOn\
 ${DDIR}.btpc.HourOff\
 ${DDIR}.btpc.!Run\
 ${DDIR}.hpcdtoppm\
 ${LDIR}.Template3D\
 ${LDIR}.Templates\
 ${MSGS} \
 ${DDIR}.djpeg.djpeg\
 ${DDIR}.djpeg.HourOn\
 ${DDIR}.djpeg.HourOff\
 ${DDIR}.djpeg.!Run\
 ${DDIR}.ChangeFSI\
 ${DDIR}.CFSIpng\
 ${DDIR}.CFSIjpeg\
 ${DDIR}.cjpeg \
 ${DDIR}.JPEGprint.!Run \
 ${DDIR}.JPEGprint.JPEGprint

#
# JPEG object files
#

# object files common to cjpeg and djpeg
COMOBJS =\
 cdjpeg.o\
 jaricom.o\
 jcomapi.o\
 jutils.o\
 jerror.o\
 jmemmgr.o\
 jmemnobs.o

# compression objects
CLIBOBJS =\
 jcapimin.o\
 jcapistd.o\
 jcinit.o\
 jcparam.o\
 jdatadst.o\
 jcmaster.o\
 jcmarker.o\
 jcmainct.o\
 jcprepct.o\
 jccoefct.o\
 jccolor.o\
 jcsample.o\
 jchuff.o\
 jcdctmgr.o\
 jcarith.o\
 jfdctfst.o\
 jfdctflt.o\
 jfdctint.o\
 cjpeg.o\
 rdppm.o\
 rdgif.o\
 rdtarga.o\
 rdrle.o\
 rdbmp.o\
 rdswitch.o

# decompression objects
DLIBOBJS =\
 jdapimin.o\
 jdapistd.o\
 jdinput.o\
 jdatasrc.o\
 jdmaster.o\
 jdmarker.o\
 jdmainct.o\
 jdcoefct.o \
 jdpostct.o\
 jddctmgr.o\
 jidctfst.o\
 jidctflt.o\
 jidctint.o\
 jdhuff.o\
 jdarith.o\
 jdsample.o\
 jdcolor.o\
 jquant1.o\
 jquant2.o\
 jdmerge.o\
 djpeg.o\
 wrgif.o\
 wrppm.o\
 wrrle.o\
 wrtarga.o\
 wrbmp.o\
 rdcolmap.o

COBJS = ${CLIBOBJS} ${COMOBJS}
DOBJS = ${DLIBOBJS} ${COMOBJS}

# btpc sources
BLIBOBJS =\
 dbtpc.o\
 colmap.o\
 compact.o\
 declevel.o\

BOBJS = ${BLIBOBJS}

# hpcdtoppm objects
HLIBOBJS =\
 main.o\
 libpbm1.o\
 color.o\
 const.o\
 error.o\
 format.o\
 output.o\
 postscr.o\
 ppm.o\
 tools.o\

HOBJS = ${HLIBOBJS}

#
# GENERIC RULES
#                  
all: ${FILES}
         @${ECHO} ${COMPONENT}: all built

#
# Note that CFSIjpeg (required) comes as a byproduct of the SprExtend component
#
install: ${FILES}
         Set Alias$CPFD ${CP} %0.%1 ${CFSIDIR}.%1 ${CPFLAGS}
         Set Alias$CPFDL CPFD %*0|MAccess ${CFSIDIR}.%1 LR/r
         |
         ${MKDIR} ${CFSIDIR}
         Access ${CFSIDIR} /r
         |
         CPFDL ${LDIR} !Help
         CPFDL ${LDIR} !Run
         CPFDL ${DDIR} !Boot
         ${MKDIR} ${CFSIDIR}.Themes.Ursula
         ${MKDIR} ${CFSIDIR}.Themes.Morris4
         ${CP} ${DDIR}.!Sprites   ${CFSIDIR}.Themes.!Sprites   ${CPFLAGS}
         ${CP} ${DDIR}.!Sprites11 ${CFSIDIR}.Themes.!Sprites11 ${CPFLAGS}
         ${CP} ${DDIR}.!Sprites22 ${CFSIDIR}.Themes.!Sprites22 ${CPFLAGS}
         ${CP} ${DDIR}.Ursula.!Sprites    ${CFSIDIR}.Themes.Ursula.!Sprites    ${CPFLAGS}
         ${CP} ${DDIR}.Ursula.!Sprites22  ${CFSIDIR}.Themes.Ursula.!Sprites22  ${CPFLAGS}
         ${CP} ${DDIR}.Morris4.!Sprites   ${CFSIDIR}.Themes.Morris4.!Sprites   ${CPFLAGS}
         ${CP} ${DDIR}.Morris4.!Sprites22 ${CFSIDIR}.Themes.Morris4.!Sprites22 ${CPFLAGS}
         ${MKDIR} ${CFSIDIR}.Documents
         CPFDL ${DDIR} Documents.256sprites
         CPFDL ${DDIR} Documents.CmdBasUse
         CPFDL ${DDIR} Documents.DesktopUse
         CPFDL ${DDIR} Documents.Formats
         CPFDL ${DDIR} Documents.JPEGInfo
         CPFDL ${DDIR} Documents.BTPCInfo
         CPFDL ${DDIR} Documents.Theory
         ${MKDIR} ${CFSIDIR}.Palettes
         CPFDL ${DDIR} Palettes.Palette2
         CPFDL ${DDIR} Palettes.Palette4
         CPFDL ${DDIR} Palettes.Palette16
         CPFDL ${DDIR} Palettes.Palette64
         CPFDL ${DDIR} Palettes.Palette256
         CPFDL ${DDIR} Palettes.CFSIict
         CPFDL ${DDIR} hpcdtoppm
         CPFDL ${DDIR} Messages
         CPFDL ${LDIR} Templates
         CPFDL ${LDIR} Template3D
         CPFDL ${DDIR} ChangeFSI
         CPFDL ${DDIR} CFSIpng
         CPFDL ${DDIR} CFSIjpeg
         CPFDL ${DDIR} cjpeg
         ${MKDIR} ${CFSIDIR}.btpc
         CPFDL ${DDIR} btpc.btpc
         CPFDL ${DDIR} btpc.!Run
         CPFDL ${DDIR} btpc.HourOn
         CPFDL ${DDIR} btpc.HourOff
         ${MKDIR} ${CFSIDIR}.djpeg
         CPFDL ${DDIR} djpeg.djpeg
         CPFDL ${DDIR} djpeg.!Run
         CPFDL ${DDIR} djpeg.HourOn
         CPFDL ${DDIR} djpeg.HourOff
         ${MKDIR} ${CFSIDIR}.JPEGprint
         CPFDL ${DDIR} JPEGprint.!Run
         CPFDL ${DDIR} JPEGprint.JPEGprint
         |
         Unset Alias$CPFDL
         Unset Alias$CPFD
         |
         @${ECHO} ${COMPONENT}: installed

clean:
         ${RM} ${DDIR}.hpcdtoppm
         ${RM} ${MSGS}
         ${RM} ${DDIR}.ChangeFSI
         ${RM} ${DDIR}.CFSIpng
         ${RM} ${DDIR}.CFSIjpeg
         ${RM} ${DDIR}.cjpeg
         ${RM} ${DDIR}.btpc.btpc
         ${RM} ${DDIR}.djpeg.djpeg
         ${RM} ${DDIR}.JPEGprint.JPEGprint
         ${XWIPE} n   ${WFLAGS}
         ${XWIPE} o.* ${WFLAGS}
         @${ECHO} ${COMPONENT}: cleaned

#------------------------------------------------------------------------------
# ChangeFSI
#------------------------------------------------------------------------------
${DDIR}.ChangeFSI: n.ChangeFSI
        ${RUN}crunch.ChangeFSI; BASIC

n.ChangeFSI: ${SDIR}.ChangeFSI ${SDIR}.DesktopFE
        ${MKDIR} n
        ${FAPPEND} n._CFSI_ ${SDIR}.DesktopFE ${SDIR}.ChangeFSI
        ${NUMBER} n._CFSI_ $@

#------------------------------------------------------------------------------
# JPEGprint
#------------------------------------------------------------------------------
${DDIR}.JPEGprint.JPEGprint: o.JPEGprint ${CLIB}
        ${LD} -o $@ o.JPEGprint ${CLIB}
        ${SQZ} $@

#------------------------------------------------------------------------------
# JPEG
#------------------------------------------------------------------------------
${DDIR}.CJpeg: ${COBJS} ${CLIB}
        ${LD} -o $@ ${COBJS} ${CLIB}
        ${SQZ} $@

${DDIR}.DJpeg.DJpeg: ${DOBJS} ${CLIB}
        ${LD} -o $@ ${DOBJS} ${CLIB}
        ${SQZ} $@

#------------------------------------------------------------------------------
# HPCDTOPPM
#------------------------------------------------------------------------------
${DDIR}.hpcdtoppm: ${HLIBOBJS} ${CLIB}
        ${LD} -o $@ ${HLIBOBJS} ${CLIB}
        ${SQZ} $@

#------------------------------------------------------------------------------
# BTPC
#------------------------------------------------------------------------------
${DDIR}.btpc.btpc: ${BOBJS} ${C++LIB} ${CLIB} 
        ${LD} -c++ -o $@ ${BOBJS} ${C++LIB} ${CLIB} 
        ${SQZ} $@

#------------------------------------------------------------------------------
# CFSIPNG
#------------------------------------------------------------------------------
${DDIR}.CFSIPNG: ${SDIR}.CFSI-PNG
        ${AS} ${ASFLAGS} -o CFSIpng.o ${SDIR}.CFSI-PNG
        ${LD} -bin -o $@ CFSIpng.o

#------------------------------------------------------------------------------
# CFSIJPEG
#------------------------------------------------------------------------------
${DDIR}.CFSIJPEG: ${SDIR}.CFSI-JPEG
        ${AS} ${ASFLAGS} -o CFSIjpeg.o ${SDIR}.CFSI-JPEG
        ${LD} -bin -o $@ CFSIjpeg.o

#------------------------------------------------------------------------------
# MESSAGES
#------------------------------------------------------------------------------
${MSGS}: ${LDIR}.Messages VersionNum
        ${INSERTVERSION} ${LDIR}.Messages > $@

# Dynamic dependencies:

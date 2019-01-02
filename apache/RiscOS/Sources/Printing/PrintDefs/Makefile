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
# Makefile for PrintDefs
#

#
# Program specific options:
#
RDIR        = Resources
RSRC        = ResSrc
LDIR        = LocalRes:${SYSTEM}
APP         = ${INSTDIR}.!${COMPONENT}
RESDIR      = <resource$dir>.Resources.${COMPONENT}

include StdTools

# Include these on disc
#
DESKTOPFILES = 

# Include these in the ROM module
#
RESFILES =                      \
 ${RDIR}.PaperA4                \
 ${RDIR}.PaperLet               \
 ${RDIR}.PaperLegal             \
 ${RDIR}.Printers.BJC50V_BW     \
 ${RDIR}.Printers.BJC50V_Col    \
 ${RDIR}.Printers.BJC600_BW     \
 ${RDIR}.Printers.BJC600_Col    \
 ${RDIR}.Printers.BJC80V_BW     \
 ${RDIR}.Printers.BJC80V_Col    \
 ${RDIR}.Printers.BJF100_BW     \
 ${RDIR}.Printers.BJF100_Col    \
 ${RDIR}.Printers.BJF200_BW     \
 ${RDIR}.Printers.BJF200_Col    \
 ${RDIR}.Printers.BubbleJet     \
 ${RDIR}.Printers.DJ500C_BW     \
 ${RDIR}.Printers.DJ500C_Col    \
 ${RDIR}.Printers.DJ660C_BW     \
 ${RDIR}.Printers.DJ660C_Col    \
 ${RDIR}.Printers.FX-80         \
 ${RDIR}.Printers.FX-85         \
 ${RDIR}.Printers.HPSDK_BW      \
 ${RDIR}.Printers.HPSDK_COL     \
 ${RDIR}.Printers.JP-150        \
 ${RDIR}.Printers.JP-192_BW     \
 ${RDIR}.Printers.JP-192_COL    \
 ${RDIR}.Printers.L6Z11_BW      \
 ${RDIR}.Printers.L6Z11_Col     \
 ${RDIR}.Printers.L6Z12_BW      \
 ${RDIR}.Printers.L6Z12_Col     \
 ${RDIR}.Printers.LasJet4       \
 ${RDIR}.Printers.LasJet5       \
 ${RDIR}.Printers.LasJetII      \
 ${RDIR}.Printers.LasJetIII     \
 ${RDIR}.Printers.LC-200_BW     \
 ${RDIR}.Printers.LC-200_Col    \
 ${RDIR}.Printers.Lex_BW        \
 ${RDIR}.Printers.Lex_Col       \
 ${RDIR}.Printers.PS_BW         \
 ${RDIR}.Printers.PS_Col        \
 ${RDIR}.Printers.StyColH_BW    \
 ${RDIR}.Printers.StyColH_Co    \
 ${RDIR}.Printers.StyCol_BW     \
 ${RDIR}.Printers.StyCol_Col    \
 ${RDIR}.Printers.Stylus-800    \
 ${RDIR}.Printers.Swift24_BW    \
 ${RDIR}.Printers.Swift24_Co

#
# RISC OS ROM build rules:
#

clean:
        ${WIPE} ${RDIR}.Printers ${WFLAGS}
        ${RM} ${RDIR}.PaperA4
        ${RM} ${RDIR}.PaperLet
        ${RM} ${RDIR}.PaperLegal
        @echo PrintDefs cleaned

dirs:
        ${MKDIR} ${RDIR}.Printers

desktopdirs:
        ${MKDIR} ${APP}.Themes
        ${MKDIR} ${APP}.Printers

resources: ${RESFILES} dirs
        ${MKDIR} ${RESDIR}
        ${MKDIR} ${RESDIR}.Palettes
        ${MKDIR} ${RESDIR}.Printers
        ${MKDIR} ${RESDIR}.ps
        ${MKDIR} ${RESDIR}.ps.Printers
        ${MKDIR} ${RESDIR}.ps.PSfiles
        ${CP} ${LDIR}.Supported            ${RESDIR}.Supported            ${CPFLAGS}
        ${CP} ${RDIR}.Palettes.*           ${RESDIR}.Palettes.*           ${CPFLAGS}
        ${CP} ${RDIR}.ps.Printers.0        ${RESDIR}.ps.Printers.0        ${CPFLAGS}
        ${CP} ${RDIR}.ps.PSfiles.PSepilog  ${RESDIR}.ps.PSfiles.PSepilog  ${CPFLAGS}
        ${CP} ${RDIR}.ps.PSfiles.PSprolog2 ${RESDIR}.ps.PSfiles.PSprolog2 ${CPFLAGS}
        ${CP} ${RDIR}.PaperA4              ${RESDIR}.PaperA4              ${CPFLAGS}
        ${CP} ${RDIR}.PaperLet             ${RESDIR}.PaperLet             ${CPFLAGS}
        ${CP} ${RDIR}.PaperLegal           ${RESDIR}.PaperLegal           ${CPFLAGS}
        ${CP} ${RDIR}.Printers.*           ${RESDIR}.Printers.*           ${CPFLAGS}
        @echo ${COMPONENT}: resource files copied

BBETYPE = printdefs
bbe-printdefs: bbe-generic-resources-get-alias
  BBE_Export_Dir Resources.Printers
  BBE_Export_Dir Resources.Palettes
  BBE_Export_Dir Resources.ps
  BBE_Export_Dir Resources.${LOCALE}.${SYSTEM}
  ${CP} ${RDIR}.PaperA4 ${BBEDIR}.Resources.PaperA4 ${CPFLAGS}
  ${CP} ${RDIR}.PaperLet ${BBEDIR}.Resources.PaperLet ${CPFLAGS}
  ${CP} ${RDIR}.PaperLegal ${BBEDIR}.Resources.PaperLegal ${CPFLAGS}

# These files are used with STB machines
# Note: STB PDFs are not compatible with desktop ones
#
installstb: ${RESFILES} dirs
        ${MKDIR} ${APP}.Printers
        ${MKDIR} ${APP}.Palettes
        ${MKDIR} ${APP}.ps
        ${CP} ${LDIR}.!Boot                ${APP}.!Boot           ${CPFLAGS}
        ${CP} ${LDIR}.Supported            ${APP}.Supported       ${CPFLAGS}
        ${CP} ${RDIR}.Palettes.*           ${APP}.Palettes.*      ${CPFLAGS}
        ${CP} ${RDIR}.ps.*                 ${APP}.ps.*            ${CPFLAGS}
        ${CP} ${RDIR}.PaperA4              ${APP}.PaperA4         ${CPFLAGS}
        ${CP} ${RDIR}.PaperLet             ${APP}.PaperLet        ${CPFLAGS}
        ${CP} ${RDIR}.PaperLegal           ${APP}.PaperLegal      ${CPFLAGS}
        ${CP} ${RDIR}.Printers.*           ${APP}.Printers.*      ${CPFLAGS}
        @echo ${COMPONENT}: install (stb disc) complete

# These files are used with desktop machines
# Note: desktop PDFs are not compatible with STB ones
#
install: ${DESKTOPFILES} desktopdirs                                 
         ${CP} ${RDIR}.!Boot                 ${APP}.!Boot             ${CPFLAGS}
         ${CP} ${RDIR}.!Run                  ${APP}.!Run              ${CPFLAGS}
         ${CP} LocalRes:!Sprites             ${APP}.Themes.!Sprites   ${CPFLAGS}
         ${CP} LocalRes:!Sprites11           ${APP}.Themes.!Sprites11 ${CPFLAGS}
         ${CP} LocalRes:!Sprites22           ${APP}.Themes.!Sprites22 ${CPFLAGS}
         ${CP} LocalRes:Ursula               ${APP}.Themes.Ursula     ${CPFLAGS}
         ${CP} LocalRes:Morris4              ${APP}.Themes.Morris4    ${CPFLAGS}
         ${CP} ${RDIR}.USBMap                ${APP}.USBMap            ${CPFLAGS}
         ${CP} LocalRes:!Help                ${APP}.!Help             ${CPFLAGS}
         ${CP} LocalRes:NonSTB.*             ${APP}.Printers.*        ${CPFLAGS}
         ${CP} ${RDIR}.NonSTB.*              ${APP}.Printers.*        ${CPFLAGS}
         ${XWIPE}                            ${APP}.Printers.PCL      ${WFLAGS}
         ${CHMOD} -f -R 444                  ${APP}
         @echo ${COMPONENT}: install (desktop disc) complete

#
# Squash resource files
#
${RDIR}.PaperA4:                ${RSRC}.A4.PaperSizes
        ${COMPRESS}     ${RSRC}.A4.PaperSizes           ${RDIR}.PaperA4

${RDIR}.PaperLet:               ${RSRC}.Letter.PaperSizes
        ${COMPRESS}     ${RSRC}.Letter.PaperSizes       ${RDIR}.PaperLet

${RDIR}.PaperLegal:             ${RSRC}.Legal.PaperSizes
        ${COMPRESS}     ${RSRC}.Legal.PaperSizes        ${RDIR}.PaperLegal

${RDIR}.Printers.BJC50V_BW:     ${RSRC}.Printers.BJC50V_BW
        ${COMPRESS}     ${RSRC}.Printers.BJC50V_BW      ${RDIR}.Printers.BJC50V_BW

${RDIR}.Printers.BJC50V_Col:    ${RSRC}.Printers.BJC50V_Col
        ${COMPRESS}     ${RSRC}.Printers.BJC50V_Col     ${RDIR}.Printers.BJC50V_Col

${RDIR}.Printers.BJC600_BW:     ${RSRC}.Printers.BJC600_BW
        ${COMPRESS}     ${RSRC}.Printers.BJC600_BW      ${RDIR}.Printers.BJC600_BW

${RDIR}.Printers.BJC600_Col:    ${RSRC}.Printers.BJC600_Col
        ${COMPRESS}     ${RSRC}.Printers.BJC600_Col     ${RDIR}.Printers.BJC600_Col

${RDIR}.Printers.BJC80V_BW:     ${RSRC}.Printers.BJC80V_BW
        ${COMPRESS}     ${RSRC}.Printers.BJC80V_BW      ${RDIR}.Printers.BJC80V_BW

${RDIR}.Printers.BJC80V_Col:    ${RSRC}.Printers.BJC80V_Col
        ${COMPRESS}     ${RSRC}.Printers.BJC80V_Col     ${RDIR}.Printers.BJC80V_Col

${RDIR}.Printers.BJF100_BW:     ${RSRC}.Printers.BJF100_BW
        ${COMPRESS}     ${RSRC}.Printers.BJF100_BW      ${RDIR}.Printers.BJF100_BW

${RDIR}.Printers.BJF100_Col:    ${RSRC}.Printers.BJF100_Col
        ${COMPRESS}     ${RSRC}.Printers.BJF100_Col     ${RDIR}.Printers.BJF100_Col

${RDIR}.Printers.BJF200_BW:     ${RSRC}.Printers.BJF200_BW
        ${COMPRESS}     ${RSRC}.Printers.BJF200_BW      ${RDIR}.Printers.BJF200_BW

${RDIR}.Printers.BJF200_Col:    ${RSRC}.Printers.BJF200_Col
        ${COMPRESS}     ${RSRC}.Printers.BJF200_Col     ${RDIR}.Printers.BJF200_Col

${RDIR}.Printers.BubbleJet:     ${RSRC}.Printers.BubbleJet
        ${COMPRESS}     ${RSRC}.Printers.BubbleJet      ${RDIR}.Printers.BubbleJet

${RDIR}.Printers.DJ500C_BW:     ${RSRC}.Printers.DJ500C_BW
        ${COMPRESS}     ${RSRC}.Printers.DJ500C_BW      ${RDIR}.Printers.DJ500C_BW

${RDIR}.Printers.DJ500C_Col:    ${RSRC}.Printers.DJ500C_Col
        ${COMPRESS}     ${RSRC}.Printers.DJ500C_Col     ${RDIR}.Printers.DJ500C_Col

${RDIR}.Printers.DJ660C_BW:     ${RSRC}.Printers.DJ660C_BW
        ${COMPRESS}     ${RSRC}.Printers.DJ660C_BW      ${RDIR}.Printers.DJ660C_BW

${RDIR}.Printers.DJ660C_Col:    ${RSRC}.Printers.DJ660C_Col
        ${COMPRESS}     ${RSRC}.Printers.DJ660C_Col     ${RDIR}.Printers.DJ660C_Col

${RDIR}.Printers.FX-80:         ${RSRC}.Printers.FX-80
        ${COMPRESS}     ${RSRC}.Printers.FX-80          ${RDIR}.Printers.FX-80

${RDIR}.Printers.FX-85:         ${RSRC}.Printers.FX-85
        ${COMPRESS}     ${RSRC}.Printers.FX-85          ${RDIR}.Printers.FX-85

${RDIR}.Printers.HPSDK_BW:      ${RSRC}.Printers.HPSDK_BW
        ${COMPRESS}     ${RSRC}.Printers.HPSDK_BW       ${RDIR}.Printers.HPSDK_BW

${RDIR}.Printers.HPSDK_COL:     ${RSRC}.Printers.HPSDK_COL
        ${COMPRESS}     ${RSRC}.Printers.HPSDK_COL      ${RDIR}.Printers.HPSDK_Col

${RDIR}.Printers.JP-150:        ${RSRC}.Printers.JP-150
        ${COMPRESS}     ${RSRC}.Printers.JP-150         ${RDIR}.Printers.JP-150

${RDIR}.Printers.JP-192_BW:     ${RSRC}.Printers.JP-192_BW
        ${COMPRESS}     ${RSRC}.Printers.JP-192_BW      ${RDIR}.Printers.JP-192_BW

${RDIR}.Printers.JP-192_COL:    ${RSRC}.Printers.JP-192_COL
        ${COMPRESS}     ${RSRC}.Printers.JP-192_COL     ${RDIR}.Printers.JP-192_Col

${RDIR}.Printers.L6Z11_BW:      ${RSRC}.Printers.L6Z11_BW
        ${COMPRESS}     ${RSRC}.Printers.L6Z11_BW       ${RDIR}.Printers.L6Z11_BW

${RDIR}.Printers.L6Z11_Col:     ${RSRC}.Printers.L6Z11_Col
        ${COMPRESS}     ${RSRC}.Printers.L6Z11_Col      ${RDIR}.Printers.L6Z11_Col

${RDIR}.Printers.L6Z12_BW:      ${RSRC}.Printers.L6Z12_BW
        ${COMPRESS}     ${RSRC}.Printers.L6Z12_BW       ${RDIR}.Printers.L6Z12_BW

${RDIR}.Printers.L6Z12_Col:     ${RSRC}.Printers.L6Z12_Col
        ${COMPRESS}     ${RSRC}.Printers.L6Z12_Col      ${RDIR}.Printers.L6Z12_Col

${RDIR}.Printers.LasJet4:       ${RSRC}.Printers.LasJet4
        ${COMPRESS}     ${RSRC}.Printers.LasJet4        ${RDIR}.Printers.LasJet4

${RDIR}.Printers.LasJet5:       ${RSRC}.Printers.LasJet5
        ${COMPRESS}     ${RSRC}.Printers.LasJet5        ${RDIR}.Printers.LasJet5

${RDIR}.Printers.LasJetII:      ${RSRC}.Printers.LasJetII
        ${COMPRESS}     ${RSRC}.Printers.LasJetII       ${RDIR}.Printers.LasJetII

${RDIR}.Printers.LasJetIII:     ${RSRC}.Printers.LasJetIII
        ${COMPRESS}     ${RSRC}.Printers.LasJetIII      ${RDIR}.Printers.LasJetIII

${RDIR}.Printers.LC-200_BW:     ${RSRC}.Printers.LC-200_BW
        ${COMPRESS}     ${RSRC}.Printers.LC-200_BW      ${RDIR}.Printers.LC-200_BW

${RDIR}.Printers.LC-200_Col:    ${RSRC}.Printers.LC-200_Col
        ${COMPRESS}     ${RSRC}.Printers.LC-200_Col     ${RDIR}.Printers.LC-200_Col

${RDIR}.Printers.Lex_BW:        ${RSRC}.Printers.Lex_BW
        ${COMPRESS}     ${RSRC}.Printers.Lex_BW         ${RDIR}.Printers.Lex_BW

${RDIR}.Printers.Lex_Col:       ${RSRC}.Printers.Lex_Col
        ${COMPRESS}     ${RSRC}.Printers.Lex_Col        ${RDIR}.Printers.Lex_Col

${RDIR}.Printers.PS_BW:         ${RSRC}.Printers.PS_BW
        ${COMPRESS}     ${RSRC}.Printers.PS_BW          ${RDIR}.Printers.PS_BW

${RDIR}.Printers.PS_Col:        ${RSRC}.Printers.PS_Col
        ${COMPRESS}     ${RSRC}.Printers.PS_Col         ${RDIR}.Printers.PS_Col

${RDIR}.Printers.StyColH_BW:    ${RSRC}.Printers.StyColH_BW
        ${COMPRESS}     ${RSRC}.Printers.StyColH_BW     ${RDIR}.Printers.StyColH_BW

${RDIR}.Printers.StyColH_Co:    ${RSRC}.Printers.StyColH_Co
        ${COMPRESS}     ${RSRC}.Printers.StyColH_Co     ${RDIR}.Printers.StyColH_Co

${RDIR}.Printers.StyCol_BW:     ${RSRC}.Printers.StyCol_BW
        ${COMPRESS}     ${RSRC}.Printers.StyCol_BW      ${RDIR}.Printers.StyCol_BW

${RDIR}.Printers.StyCol_Col:    ${RSRC}.Printers.StyCol_Col
        ${COMPRESS}     ${RSRC}.Printers.StyCol_Col     ${RDIR}.Printers.StyCol_Col

${RDIR}.Printers.Stylus-800:    ${RSRC}.Printers.Stylus-800
        ${COMPRESS}     ${RSRC}.Printers.Stylus-800     ${RDIR}.Printers.Stylus-800

${RDIR}.Printers.Swift24_BW:    ${RSRC}.Printers.Swift24_BW
        ${COMPRESS}     ${RSRC}.Printers.Swift24_BW     ${RDIR}.Printers.Swift24_BW

${RDIR}.Printers.Swift24_Co:    ${RSRC}.Printers.Swift24_Co
        ${COMPRESS}     ${RSRC}.Printers.Swift24_Co     ${RDIR}.Printers.Swift24_Co


#---------------------------------------------------------------------------
# Dynamic dependencies:

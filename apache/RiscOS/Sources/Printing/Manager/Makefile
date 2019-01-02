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
# Makefile for Printers {Printer Manager}
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 16-Sep-94  AMcC   Merged PrintersF and PrintersB
# 20-Oct-94  AMcC   Corrected disc-based installation
#                   Corrected rmensures for remote printer modules
# 29-Oct-94  AMcC   Don't include !Printers.!Sprites in Resources (now in Wimp.Sprites)
#                   Do include Sprites22 for dp, lj, ps Resources
#                   Make sure that ${LDIR}.!RunLink gets made before copying Resources
# 08-Nov-94  MJS    Add Palettes.1 (as 0, but gamma is 0.4 instead of 0.6), used by
#                   Stylus-Col and Stylus-Cmw PDF's
# 03-Mar-95  MJS    Add Palettes.2 (very special palette for Stylus at 720 dpi)
# 25-Nov-02  RPS    Insert the version number in the Messages file at build time
# 12-May-04  JWB    Build using DummyParallel for tungsten usage
#

#
# Program specific options:
#
COMPONENT  = Printers
APP        = !Printers
ROM_MODULE = rm.Printers
DDIR       = DataFiles
LDIR       = ${LOCALE}
SDIR       = sources

#
# Export Paths for Messages module
#
RESDIR     = <resource$dir>.Resources.${COMPONENT}
RESAPP     = <resource$dir>.Apps.${APP}

include StdTools

#
# Specific (weird) tools:
#
CRUNCH     = bascrunch
PSSHRINK   = psshrink

#
# Tool flags:
#
ASFLAGS    = -Stamp -quit -depend !Depend ${THROWBACK}
DFLAGS    += -DSparrow
CFLAGS     = -c++ -j^ ${THROWBACK} ${DFLAGS}
CPFLAGS    = ~cfr~v
CRFLAGS    = %11111
SQFLAGS    =  -nolist

DPFILES = \
        ${DDIR}.dp.PrData \
        ${DDIR}.dp.Template \
        squished.SupportDP \
        ${DDIR}.dp.Resources.!Sprites \
        ${DDIR}.dp.Resources.!Sprites22 \
        ${DDIR}.dp.Resources.!Sprites11 \
        ${DDIR}.dp.Resources.Ursula.!Sprites \
        ${DDIR}.dp.Resources.Ursula.!Sprites22 \
        ${DDIR}.dp.Resources.Morris4.!Sprites \
        ${DDIR}.dp.Resources.Morris4.!Sprites22 \
        ${LDIR}.dp.Resources.Messages \
        ${DDIR}.dp.Resources.PaperRO \
        ${LDIR}.dp.Resources.Template3D \
        ${LDIR}.dp.Resources.Templates
#
LJFILES = \
        ${DDIR}.lj.PrData \
        ${DDIR}.lj.Template \
        squished.SupportLJ \
        ${DDIR}.lj.Resources.!Sprites \
        ${DDIR}.lj.Resources.!Sprites22 \
        ${DDIR}.lj.Resources.!Sprites11 \
        ${DDIR}.lj.Resources.Ursula.!Sprites \
        ${DDIR}.lj.Resources.Ursula.!Sprites22 \
        ${DDIR}.lj.Resources.Morris4.!Sprites \
        ${DDIR}.lj.Resources.Morris4.!Sprites22 \
        ${LDIR}.lj.Resources.Messages \
        ${DDIR}.lj.Resources.PaperRO \
        ${LDIR}.lj.Resources.Template3D \
        ${LDIR}.lj.Resources.Templates
#
PROLOGS = \
        prolog.OldLatin1 \
        prolog.PSepilog \
        prolog.PSprolog \
        prolog_z.Level1.PSprolog2 \
        prolog_z.Level2.PSprolog2 \
        prolog_z.PStprolog \
        prolog.Selwyn \
        prolog.Sidney

PSFILES = \
        ${DDIR}.ps.PrData \
        ${DDIR}.ps.Template \
        squished.SupportPS \
        ${DDIR}.ps.Resources.!Sprites \
        ${DDIR}.ps.Resources.!Sprites22 \
        ${DDIR}.ps.Resources.!Sprites11 \
        ${DDIR}.ps.Resources.Ursula.!Sprites \
        ${DDIR}.ps.Resources.Ursula.!Sprites22 \
        ${DDIR}.ps.Resources.Morris4.!Sprites \
        ${DDIR}.ps.Resources.Morris4.!Sprites22 \
        ${LDIR}.ps.Resources.Messages \
        ${DDIR}.ps.Resources.PaperRO \
        ${LDIR}.ps.Resources.Template3D \
        ${LDIR}.ps.Resources.Templates \
        ${DDIR}.ps.Adobe.Special \
        ${DDIR}.ps.Adobe.Standard \
        $(DDIR).ps.Paper.a0 \
        $(DDIR).ps.Paper.a1 \
        $(DDIR).ps.Paper.a2 \
        $(DDIR).ps.Paper.a3 \
        $(DDIR).ps.Paper.a4 \
        $(DDIR).ps.Paper.a5 \
        $(DDIR).ps.Paper.legal \
        $(DDIR).ps.Paper.letter \
        ${PROLOGS}

FILES = \
        ${DDIR}.!Boot \
        ${LDIR}.!Help \
        ${LDIR}.!Run \
        ${DDIR}.!Sprites \
        ${DDIR}.!Sprites22 \
        ${DDIR}.!Sprites11 \
        ${DDIR}.Ursula.!Sprites \
        ${DDIR}.Ursula.!Sprites22 \
        ${DDIR}.Morris4.!Sprites \
        ${DDIR}.Morris4.!Sprites22 \
        ${DDIR}.Code \
        ${DDIR}.Messages \
        ${DDIR}.Palettes.0 \
        ${DDIR}.Palettes.1 \
        ${DDIR}.Palettes.2 \
        ${DDIR}.Palettes.3 \
        ${DDIR}.Palettes.4 \
        ${DDIR}.Palettes.5 \
        ${DDIR}.Palettes.6 \
        ${DDIR}.Palettes.7 \
        ${DDIR}.Palettes.8 \
        ${DDIR}.Palettes.9 \
        ${DDIR}.Palettes.10 \
        ${DDIR}.Palettes.11 \
        ${DDIR}.Palettes.12 \
        ${DDIR}.Palettes.13 \
        ${DDIR}.Palettes.14 \
        ${DDIR}.Palettes.15 \
        ${DDIR}.Palettes.20 \
        ${LDIR}.PaperRO \
        ${LDIR}.Template3D \
        ${LDIR}.Templates \
        util.SetPrint \
        ${DPFILES} \
        ${LJFILES} \
        ${PSFILES}

DISC_FILES =\
        squished.RunImage \
        ${FILES}

# these are included in the ROM module
RESFILES =\
        squished.RunImageR \
        ${DDIR}.Code \
        ${DDIR}.Palettes.0 \
        ${DDIR}.Palettes.1 \
        ${DDIR}.Palettes.2 \
        ${DDIR}.Palettes.3 \
        ${DDIR}.Palettes.4 \
        ${DDIR}.Palettes.5 \
        ${DDIR}.Palettes.6 \
        ${DDIR}.Palettes.7 \
        ${DDIR}.Palettes.8 \
        ${DDIR}.Palettes.9 \
        ${DDIR}.Palettes.10 \
        ${DDIR}.Palettes.11 \
        ${DDIR}.Palettes.12 \
        ${DDIR}.Palettes.13 \
        ${DDIR}.Palettes.14 \
        ${DDIR}.Palettes.15 \
        ${DDIR}.Palettes.20 \
        util.SetPrint \
        sources.DummyDP \
        ${DDIR}.dp.PrData \
        ${DDIR}.dp.Template \
        ${DDIR}.dp.Resources.!Sprites \
        ${DDIR}.dp.Resources.!Sprites22 \
        ${DDIR}.dp.Resources.PaperRO \
        sources.DummyLJ \
        ${DDIR}.lj.PrData \
        ${DDIR}.lj.Template \
        ${DDIR}.lj.Resources.!Sprites \
        ${DDIR}.lj.Resources.!Sprites22 \
        ${DDIR}.lj.Resources.PaperRO \
        sources.DummyPS \
        ${DDIR}.ps.PrData \
        ${DDIR}.ps.Template \
        ${DDIR}.ps.Resources.!Sprites \
        ${DDIR}.ps.Resources.!Sprites22 \
        ${DDIR}.ps.Resources.PaperRO \
        ${DDIR}.ps.Adobe.Special \
        ${DDIR}.ps.Adobe.Standard \
        $(DDIR).ps.Paper.a0 \
        $(DDIR).ps.Paper.a1 \
        $(DDIR).ps.Paper.a2 \
        $(DDIR).ps.Paper.a3 \
        $(DDIR).ps.Paper.a4 \
        $(DDIR).ps.Paper.a5 \
        $(DDIR).ps.Paper.legal \
        $(DDIR).ps.Paper.letter \
        ${PROLOGS}

#
# Rule patterns
#
.SUFFIXES: .prolog .prolog_z

.prolog.prolog_z:;  ${PSSHRINK} -in $< -out $@ -type FFF

#
# Generic rules:
#
all: ${DISC_FILES} local_dirs
        @${ECHO} ${COMPONENT}: all built (Disc version)

rom:  ${ROM_MODULE} local_dirs
        @${ECHO} ${COMPONENT}: all built (ROM version)

export: ${EXPORTS}
        @${ECHO} ${COMPONENT}: export complete

install: ${DISC_FILES} dirs local_dirs
        Access ${INSTDIR} WR/r
        |
        Access ${INSTDIR}.dp WR/r
        Access ${INSTDIR}.lj WR/r
        Access ${INSTDIR}.ps WR/r
        Access ${INSTDIR}.dp.Resources WR/r
        Access ${INSTDIR}.lj.Resources WR/r
        Access ${INSTDIR}.ps.Resources WR/r
        Access ${INSTDIR}.ps.Adobe WR/r
        Access ${INSTDIR}.ps.Paper WR/r
        Access ${INSTDIR}.ps.Printers WR/r
        Access ${INSTDIR}.ps.PSFiles WR/r
        Access ${INSTDIR}.ps.PSFiles.Level1 WR/r
        Access ${INSTDIR}.ps.PSFiles.Level2 WR/r
        Access ${INSTDIR}.Remote WR/wr
        Access ${INSTDIR}.Palettes WR/r
        |
        set Alias$CPFD ${CP} %0 ${INSTDIR}.%1 ${CPFLAGS}
        set Alias$CPFDL CPFD %*0|MAccess ${INSTDIR}.%1 LR/r
        |
        CPFDL ${DDIR}.!Boot      !Boot
        CPFDL ${LDIR}.!Run       !Run
        CPFDL ${LDIR}.!Help      !Help
        CPFDL squished.RunImage  !RunImage
        CPFDL ${DDIR}.!Sprites   Themes.!Sprites
        CPFDL ${DDIR}.!Sprites22 Themes.!Sprites22
        CPFDL ${DDIR}.!Sprites11 Themes.!Sprites11
        CPFDL ${DDIR}.Ursula.!Sprites    Themes.Ursula.!Sprites
        CPFDL ${DDIR}.Ursula.!Sprites22  Themes.Ursula.!Sprites22
        CPFDL ${DDIR}.Morris4.!Sprites   Themes.Morris4.!Sprites
        CPFDL ${DDIR}.Morris4.!Sprites22 Themes.Morris4.!Sprites22
        CPFDL ${DDIR}.Code       Code
        CPFDL ${DDIR}.Messages   Messages
        CPFDL ${DDIR}.Palettes.0 Palettes.0
        CPFDL ${DDIR}.Palettes.1 Palettes.1
        CPFDL ${DDIR}.Palettes.2 Palettes.2
        CPFDL ${DDIR}.Palettes.3 Palettes.3
        CPFDL ${DDIR}.Palettes.4 Palettes.4
        CPFDL ${DDIR}.Palettes.5 Palettes.5
        CPFDL ${DDIR}.Palettes.6 Palettes.6
        CPFDL ${DDIR}.Palettes.7 Palettes.7
        CPFDL ${DDIR}.Palettes.8 Palettes.8
        CPFDL ${DDIR}.Palettes.9 Palettes.9
        CPFDL ${DDIR}.Palettes.10 Palettes.10
        CPFDL ${DDIR}.Palettes.11 Palettes.11
        CPFDL ${DDIR}.Palettes.12 Palettes.12
        CPFDL ${DDIR}.Palettes.13 Palettes.13
        CPFDL ${DDIR}.Palettes.14 Palettes.14
        CPFDL ${DDIR}.Palettes.20 Palettes.20
        CPFDL ${LDIR}.PaperRO    PaperRO
        CPFDL util.SetPrint      SetPrint
        CPFDL ${LDIR}.Templates  Templates
        CPFDL ${LDIR}.Template3D Template3D
        |
        CPFD  ${DDIR}.dp.PrData               dp.PrData
        CPFDL ${DDIR}.dp.Template             dp.Template
        CPFDL ${DDIR}.dp.Resources.!Sprites   dp.Resources.!Sprites
        CPFDL ${DDIR}.dp.Resources.!Sprites22 dp.Resources.!Sprites22
        CPFDL ${DDIR}.dp.Resources.!Sprites11 dp.Resources.!Sprites11
        CPFDL ${DDIR}.dp.Resources.Morris4.!Sprites   dp.Resources.Morris4.!Sprites
        CPFDL ${DDIR}.dp.Resources.Morris4.!Sprites22 dp.Resources.Morris4.!Sprites22
        CPFDL ${DDIR}.dp.Resources.Ursula.!Sprites    dp.Resources.Ursula.!Sprites
        CPFDL ${DDIR}.dp.Resources.Ursula.!Sprites22  dp.Resources.Ursula.!Sprites22
        CPFDL ${LDIR}.dp.Resources.Messages   dp.Resources.Messages
        CPFDL ${DDIR}.dp.Resources.PaperRO    dp.Resources.PaperRO
        CPFDL squished.SupportDP              dp.Resources.Support
        CPFDL ${LDIR}.dp.Resources.Templates  dp.Resources.Templates
        CPFDL ${LDIR}.dp.Resources.Template3D dp.Resources.Template3D
        |
        CPFD  ${DDIR}.lj.PrData               lj.PrData
        CPFDL ${DDIR}.lj.Template             lj.Template
        CPFDL ${DDIR}.lj.Resources.!Sprites   lj.Resources.!Sprites
        CPFDL ${DDIR}.lj.Resources.!Sprites22 lj.Resources.!Sprites22
        CPFDL ${DDIR}.lj.Resources.!Sprites11 lj.Resources.!Sprites11
        CPFDL ${DDIR}.lj.Resources.Morris4.!Sprites   lj.Resources.Morris4.!Sprites
        CPFDL ${DDIR}.lj.Resources.Morris4.!Sprites22 lj.Resources.Morris4.!Sprites22
        CPFDL ${DDIR}.lj.Resources.Ursula.!Sprites    lj.Resources.Ursula.!Sprites
        CPFDL ${DDIR}.lj.Resources.Ursula.!Sprites22  lj.Resources.Ursula.!Sprites22
        CPFDL ${LDIR}.lj.Resources.Messages   lj.Resources.Messages
        CPFDL ${DDIR}.lj.Resources.PaperRO    lj.Resources.PaperRO
        CPFDL squished.SupportLJ              lj.Resources.Support
        CPFDL ${LDIR}.lj.Resources.Templates  lj.Resources.Templates
        CPFDL ${LDIR}.lj.Resources.Template3D lj.Resources.Template3D
        |
        CPFD  ${DDIR}.ps.PrData               ps.PrData
        CPFDL ${DDIR}.ps.Template             ps.Template
        CPFDL ${DDIR}.ps.Resources.!Sprites   ps.Resources.!Sprites
        CPFDL ${DDIR}.ps.Resources.!Sprites22 ps.Resources.!Sprites22
        CPFDL ${DDIR}.ps.Resources.!Sprites11 ps.Resources.!Sprites11
        CPFDL ${DDIR}.ps.Resources.Morris4.!Sprites   ps.Resources.Morris4.!Sprites
        CPFDL ${DDIR}.ps.Resources.Morris4.!Sprites22 ps.Resources.Morris4.!Sprites22
        CPFDL ${DDIR}.ps.Resources.Ursula.!Sprites    ps.Resources.Ursula.!Sprites
        CPFDL ${DDIR}.ps.Resources.Ursula.!Sprites22  ps.Resources.Ursula.!Sprites22
        CPFDL ${LDIR}.ps.Resources.Messages   ps.Resources.Messages
        CPFDL ${DDIR}.ps.Resources.PaperRO    ps.Resources.PaperRO
        CPFDL squished.SupportPS              ps.Resources.Support
        CPFDL ${LDIR}.ps.Resources.Templates  ps.Resources.Templates
        CPFDL ${LDIR}.ps.Resources.Template3D ps.Resources.Template3D
        CPFDL ${DDIR}.ps.Adobe.Special        ps.Adobe.Special
        CPFDL ${DDIR}.ps.Adobe.Standard       ps.Adobe.Standard
        CPFDL ${DDIR}.ps.Paper.a0             ps.Paper.a0
        CPFDL ${DDIR}.ps.Paper.a1             ps.Paper.a1
        CPFDL ${DDIR}.ps.Paper.a2             ps.Paper.a2
        CPFDL ${DDIR}.ps.Paper.a3             ps.Paper.a3
        CPFDL ${DDIR}.ps.Paper.a4             ps.Paper.a4
        CPFDL ${DDIR}.ps.Paper.a5             ps.Paper.a5
        CPFDL ${DDIR}.ps.Paper.legal          ps.Paper.legal
        CPFDL ${DDIR}.ps.Paper.letter         ps.Paper.letter
        CPFDL prolog.OldLatin1                ps.PSFiles.OldLatin1
        CPFDL prolog.PSepilog                 ps.PSFiles.PSepilog
        CPFDL prolog.PSprolog                 ps.PSFiles.PSprolog
        CPFDL prolog_z.Level1.PSprolog2       ps.PSFiles.Level1.PSprolog2
        CPFDL prolog_z.Level2.PSprolog2       ps.PSFiles.Level2.PSprolog2
        CPFDL prolog_z.PStprolog              ps.PSFiles.PStprolog
        CPFDL prolog.Selwyn                   ps.PSFiles.Selwyn
        CPFDL prolog.Sidney                   ps.PSFiles.Sidney
        |
        Unset Alias$CPFD
        Unset Alias$CPFDL
        @${ECHO} ${COMPONENT}: disc install done

install_rom: ${ROM_MODULE} local_dirs
        ${CP} ${ROM_MODULE} ${INSTDIR}.Printers ${CPFLAGS}
        @${ECHO} ${COMPONENT}: rom module installed

resources: ${LDIR}.!RunLink
        ${MKDIR} ${RESAPP}
        ${MKDIR} ${RESDIR}.dp.Resources
        ${MKDIR} ${RESDIR}.lj.Resources
        ${MKDIR} ${RESDIR}.ps.Resources
        ${CP} ${DDIR}.ROM.!Boot               ${RESAPP}.!Boot     ${CPFLAGS}
        ${CP} ${LDIR}.!Help                   ${RESAPP}.!Help     ${CPFLAGS}
        ${CP} ${DDIR}.ROM.!Run                ${RESAPP}.!Run      ${CPFLAGS}
        ${CP} ${LDIR}.!RunLink                ${RESDIR}.!RunLink  ${CPFLAGS}
        ${CP} ${DDIR}.Messages                ${RESDIR}.Messages  ${CPFLAGS}
        ${CP} ${LDIR}.PaperRO                 ${RESDIR}.PaperRO   ${CPFLAGS}
        ${CP} ${LDIR}.Template3D              ${RESDIR}.Templates ${CPFLAGS}
        ${CP} ${LDIR}.dp.Resources.Messages   ${RESDIR}.dp.Resources.Messages  ${CPFLAGS}
        ${CP} ${LDIR}.lj.Resources.Messages   ${RESDIR}.lj.Resources.Messages  ${CPFLAGS}
        ${CP} ${LDIR}.ps.Resources.Messages   ${RESDIR}.ps.Resources.Messages  ${CPFLAGS}
        ${CP} ${LDIR}.dp.Resources.Template3D ${RESDIR}.dp.Resources.Templates ${CPFLAGS}
        ${CP} ${LDIR}.lj.Resources.Template3D ${RESDIR}.lj.Resources.Templates ${CPFLAGS}
        ${CP} ${LDIR}.ps.Resources.Template3D ${RESDIR}.ps.Resources.Templates ${CPFLAGS}
        @${ECHO} ${COMPONENT}: resource files copied to Messages module

clean:
        ${RM} ${DDIR}.Code
        ${RM} ${DDIR}.Messages
        ${RM} ${LDIR}.!RunLink
        ${RM} ${ROM_MODULE}
        ${RM} rm.PrintersD
        ${RM} s.Version
        ${RM} util.SetPrint
        ${RM} h.ConstVals
        ${XWIPE} crunched ${WFLAGS}
        ${XWIPE} i ${WFLAGS}
        ${XWIPE} n ${WFLAGS}
        ${XWIPE} o ${WFLAGS}
        ${XWIPE} rm ${WFLAGS}
        ${XWIPE} squished ${WFLAGS}
        ${XWIPE} prolog_z.Level1.* ${WFLAGS}
        ${XWIPE} prolog_z.Level2.* ${WFLAGS}
        @${ECHO} ${COMPONENT}: cleaned

local_dirs:
        ${MKDIR} crunched
        ${MKDIR} i
        ${MKDIR} n
        ${MKDIR} o
        ${MKDIR} rm
        ${MKDIR} squished

dirs:
        ${MKDIR} ${INSTDIR}.dp.Resources
        ${MKDIR} ${INSTDIR}.dp.Resources.Ursula
        ${MKDIR} ${INSTDIR}.dp.Resources.Morris4
        ${MKDIR} ${INSTDIR}.lj.Resources
        ${MKDIR} ${INSTDIR}.lj.Resources.Ursula
        ${MKDIR} ${INSTDIR}.lj.Resources.Morris4
        ${MKDIR} ${INSTDIR}.ps.Adobe
        ${MKDIR} ${INSTDIR}.ps.Paper
        ${MKDIR} ${INSTDIR}.ps.Feeds
        ${MKDIR} ${INSTDIR}.ps.Printers
        ${MKDIR} ${INSTDIR}.ps.PSFiles.Level1
        ${MKDIR} ${INSTDIR}.ps.PSFiles.Level2
        ${MKDIR} ${INSTDIR}.ps.Resources
        ${MKDIR} ${INSTDIR}.ps.Resources.Ursula
        ${MKDIR} ${INSTDIR}.ps.Resources.Morris4
        ${MKDIR} ${INSTDIR}.Palettes
        ${MKDIR} ${INSTDIR}.Remote
        ${MKDIR} ${INSTDIR}.Modules
        ${MKDIR} ${INSTDIR}.Themes.Ursula
        ${MKDIR} ${INSTDIR}.Themes.Morris4

${ROM_MODULE}: s.Main s.Version ${RESFILES}
        ${MKDIR} o
        ${AS} ${ASFLAGS} -o o.Printers s.Main
        ${LD} -rmf -o $@ o.Printers

${DDIR}.Messages: ${LDIR}.Messages awk.Version
        ${AWK} -f awk.Version ${LDIR}.Messages > $@

s.Version: ${DDIR}.Messages
        ${AWK} -f awk.VersionS ${DDIR}.Messages > $@

rm.PrintersD: s.MainD
        ${MKDIR} o
        ${AS} ${ASFLAGS} -o o.PrintersD s.MainD
        ${LD} -rmf -o $@ o.PrintersD
        @${ECHO} ${COMPONENT}: debugging module built

${LDIR}.!RunLink: sources.!RunLink
        ${SQUISH} ${SQFLAGS} -from sources.!RunLink -to $@

util.SetPrint: s.SetPrint
        ${MKDIR} o
        ${AS} ${ASFLAGS} -o o.SetPrint s.SetPrint
        ${LD} -bin -o $@ o.SetPrint
        ${SETTYPE} $@ FFC

prolog_z.Level1.PSprolog2: prolog.PSprolog2 \
    ; ${PSSHRINK} -in prolog.PSprolog2 -out $@ -type FFF -level 1

prolog_z.Level2.PSprolog2: prolog.PSprolog2 \
    ; ${PSSHRINK} -in prolog.PSprolog2 -out $@ -type FFF -level 2

#----------------------------------------------------------------------------
# Printer Manager (front-end): !Printers.!RunImage - DISC
#----------------------------------------------------------------------------

squished.RunImage: crunched.RunImage  ${SDIR}.Export
        ${SQUISH} ${SQFLAGS} -keep ${SDIR}.Export -from crunched.RunImage -to $@

crunched.RunImage: n.RunImage
        ${RUN}crunch.RunImage; BASIC

n.RunImage: i.RunImage
        ${NUMBER} i.RunImage $@

i.RunImage: ${SDIR}.RunImage ${SDIR}.Sparrow h.Values
        ${CC} -DDISC ${CFLAGS} -E ${SDIR}.RunImage > $@

#----------------------------------------------------------------------------
# Printer Manager (front-end): !Printers.!RunImage - ROM
#----------------------------------------------------------------------------

squished.RunImageR: crunched.RunImageR  ${SDIR}.Export
        ${SQUISH} ${SQFLAGS} -keep ${SDIR}.Export -from crunched.RunImageR -to $@

crunched.RunImageR: n.RunImageR
        ${RUN}crunch.RunImageR; BASIC

n.RunImageR: i.RunImageR
        ${NUMBER} i.RunImageR $@

i.RunImageR: ${SDIR}.RunImage ${SDIR}.Sparrow h.Values
        ${CC} -UDISC ${CFLAGS} -E ${SDIR}.RunImage > $@

#----------------------------------------------------------------------------
# Note: output filename "DataFiles.Code" is coded into SuppSrc
DataFiles.Code: i.SuppSrc
        ${RUN}BASIC -quit i.SuppSrc        

i.SuppSrc: ${SDIR}.SuppSrc  h.Values
        ${RUN}util.MkConstVal h.Values h.ConstVals
        ${RUN}util.Constants  ${SDIR}.SuppSrc $@ h.ConstVals

#----------------------------------------------------------------------------
# Dot-matrix support: !Printers.dp.Resources.Support
#----------------------------------------------------------------------------

squished.SupportDP: crunched.SupportDP  ${SDIR}.Export
        ${SQUISH} ${SQFLAGS} -keep ${SDIR}.Export -prefix dp_ -from crunched.SupportDP -to $@

crunched.SupportDP: n.SupportDP
        ${RUN}crunch.SupportDP; BASIC

n.SupportDP: i.SupportDP
        ${NUMBER} i.SupportDP $@

i.SupportDP: ${SDIR}.SupportDP  h.Values
        ${CC} ${CFLAGS} -E ${SDIR}.SupportDP > $@

#----------------------------------------------------------------------------
# LaserJet support: !Printers.lj.Resources.Support
#----------------------------------------------------------------------------

squished.SupportLJ: crunched.SupportLJ  ${SDIR}.Export
        ${SQUISH} ${SQFLAGS} -keep ${SDIR}.Export -prefix lj_ -from crunched.SupportLJ -to $@

crunched.SupportLJ: n.SupportLJ
        ${RUN}crunch.SupportLJ; BASIC

n.SupportLJ: i.SupportLJ
        ${NUMBER} i.SupportLJ $@

i.SupportLJ: ${SDIR}.SupportLJ h.values
        ${CC} ${CFLAGS} -E ${SDIR}.SupportLJ > $@

#----------------------------------------------------------------------------
# PostScript support: !Printers.ps.Resources.Support
#----------------------------------------------------------------------------

squished.SupportPS: crunched.SupportPS  ${SDIR}.Export
        ${SQUISH} ${SQFLAGS} -keep ${SDIR}.Export -prefix ps_ -from crunched.SupportPS -to $@

crunched.SupportPS: n.SupportPS
        ${RUN}crunch.SupportPS; BASIC

n.SupportPS: i.SupportPS
        ${NUMBER} i.SupportPS $@

i.SupportPS: ${SDIR}.SupportPS h.values
        ${CC} ${CFLAGS} -E ${SDIR}.SupportPS > $@

#----------------------------------------------------------------------------
# Dynamic dependencies:

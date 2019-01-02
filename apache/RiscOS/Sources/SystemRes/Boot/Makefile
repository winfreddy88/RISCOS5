# Copyright 1999 Pace Micro Technology plc
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
# Makefile for Boot
#

#---------------------------------------------------------------------------
# COMPONENT = ...
#   This must be set on the command line to one of Boot, ShareBoot,
#   ArmBoot, ResetBoot. Case is important. INSTDIR must also set, as usual.
APP        = !${COMPONENT}
RDIR       = ${COMPONENT}
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

include StdTools
include StdRules
include AppLibs

CDEFINES  += -DCOMPAT_INET4
CINCLUDES += -ITCPIPLibs:,C:,OSLib:
CFLAGS    += -Wp 

#---------------------------------------------------------------------------
# File selections

# Files which are part of the Universal boot sequence
FILESUNIVERSAL = \
   Utils.BootVars \
   Library.PowerOff \
   Configure.ClrMonitor \
   ${FILES310} \
   ${FILES350} \
   ${FILES360} \
   ${FILES370} \
   ${FILES400} \
   ${FILES430} \
   ${FILES500} \
   ${FILES510} \
   ${FILES520} \

# Files required by a 3.1x machine
FILES310 = \
   RO310Hook \

# Files required by a 3.5x machine
FILES350 = \
   RO350Hook \
   RO350Hook.Boot.PreDesk.MemFix \
   RO350Hook.Boot.PreDesk.DPMSUtils \
   RO350Hook.Boot.PreDesk.WimpUtils \
   RO350Hook.Boot.PreDesk.ROMPatch \

# Files required by a 3.6x machine
FILES360 = \
   RO360Hook \
   RO360Hook.Boot.Tasks.~CDReinit \
   RO360Hook.Boot.PreDesk.ROMPatch \

# Files required by a 3.7x machine
FILES370 = \
   RO370Hook \
   RO370Hook.Boot.PreDesk.Configure.BandLimit \
   RO370Hook.Boot.Tasks.~CDReinit \
   RO370Hook.Boot.PreDesk.ROMPatch \

# Files required by a 4.0x machine
FILES400 = \
   RO400Hook \
   RO400Hook.Boot.PreDesk.Configure.BandLimit \
   RO400Hook.Boot.Tasks.~CDReinit \
   RO400Hook.Boot.PreDesk.ROMPatch \

# Files required by a 4.3x machine
FILES430 = \
   RO430Hook \
   RO430Hook.Boot.PreDesk.Configure.BandLimit \
   RO430Hook.Boot.Tasks.~CDReinit \

# Files required by a 5.0x machine
FILES500 = \
   RO500Hook \

# Files required by a 5.1x machine
FILES510 = \
   RO510Hook \

# Files required by a 5.2x machine
FILES520 = \
   RO520Hook \

#---------------------------------------------------------------------------
# Main rules:
install: install_${COMPONENT}${TARGET}
   @echo ${COMPONENT}: installed (Disc)

# Files which hang together at the top of !Boot (the sprites are picked on a UserIF basis)
install_AppFiles: ${COMPONENT}.TmpRun
   ${MKDIR}                                     ${INSTAPP}
   ${CP} ${LDIR}.!Boot                          ${INSTAPP}.!Boot ${CPFLAGS}
   ${CP} ${LDIR}.!Help                          ${INSTAPP}.!Help ${CPFLAGS}
   ${CP} ${COMPONENT}.TmpRun                    ${INSTAPP}.!Run  ${CPFLAGS}
   ${MKDIR}                                     ${INSTAPP}.Themes
   ${CP} ${RDIR}.Iyonix.!Sprites                ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
   ${CP} ${RDIR}.Iyonix.!Sprites22              ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
   ${CP} ${RDIR}.Iyonix.!Sprites11              ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
   ${CP} ${RDIR}.Morris4                        ${INSTAPP}.Themes.Morris4    ${CPFLAGS}
   ${CP} ${RDIR}.Ursula                         ${INSTAPP}.Themes.Ursula     ${CPFLAGS}
   ${CHMOD} 444 ${INSTAPP}.*

# Files residing in !Boot.Resources.Configure
install_Configure:
   ${MKDIR}                                     ${INSTAPP}.Resources.Configure
   ${CP} Configure.ClrMonitor                   ${INSTAPP}.Resources.Configure.ClrMonitor ${CPFLAGS}
   ${CP} Configure.FontChange                   ${INSTAPP}.Resources.Configure.FontChange ${CPFLAGS}
   ${CP} Configure.IconChange                   ${INSTAPP}.Resources.Configure.IconChange ${CPFLAGS}
   ${CP} Configure.Monitors                     ${INSTAPP}.Resources.Configure.Monitors   ${CPFLAGS}
   ${CP} Configure.Textures.Universal           ${INSTAPP}.Resources.Configure.Textures   ${CPFLAGS}
   ${CP} Configure.Extras.Universal.2DTools     ${INSTAPP}.Resources.Configure.2DTools    ${CPFLAGS}
   ${CHMOD} -R 444 ${INSTAPP}.Resources.Configure

install_BootTEXTURES installShareBootTEXTURES installArmBootTEXTURES:
   ${MKDIR}                                     ${INSTAPP}.Resources.Configure.Textures.${USERIF}
   ${CP} Configure.Textures.${USERIF}           ${INSTAPP}.Resources.Configure.Textures.${USERIF} ${CPFLAGS}
   ${CHMOD} -R 444 ${INSTAPP}.Resources.Configure

# Make me a universal !Boot
install_BootUNIVERSAL: install_Configure ${FILESUNIVERSAL} install_AppFiles
   ${MKDIR}                                     ${INSTAPP}.Choices
   ${CP} Utils                                  ${INSTAPP}.Utils ${CPFLAGS}
   ${CP} Library                                ${INSTAPP}.Library ${CPFLAGS}
   ${CHMOD} -R 744 ${INSTAPP}.Choices
   ${CHMOD} -R 444 ${INSTAPP}.Utils
   ${CHMOD} -R 444 ${INSTAPP}.Library
   @Echo Deleting superfluous files ...
   ${XWIPE}                                     ${INSTAPP}.RO350Hook.Boot.Tasks.!ROMPatch ${WFLAGS} # Now in PreDesk
   ${XWIPE}                                     ${INSTAPP}.RO430Hook ${WFLAGS} # Needs more testing really
   ${XWIPE}                                     ${INSTAPP}.Utils.NetBye ${WFLAGS} # Unreferenced
   ${XWIPE}                                     ${INSTAPP}.Library.Repeat ${WFLAGS} # Now in BootCommands

# Make me a network fileserver remote !Boot
install_ShareBootUNIVERSAL: install_Configure ${FILESUNIVERSAL} install_AppFiles
   ${MKDIR}                                     ${INSTAPP}.Choices
   ${MKDIR}                                     ${INSTAPP}.MchConfig
   ${MKDIR}                                     ${INSTAPP}.SiteHook
   ${CP} Utils                                  ${INSTAPP}.Utils ${CPFLAGS}
   ${CP} Library                                ${INSTAPP}.Library ${CPFLAGS}
   ${CHMOD} -R 744 ${INSTAPP}.Choices
   ${CHMOD} -R 444 ${INSTAPP}.Utils
   ${CHMOD} -R 444 ${INSTAPP}.Library
   @Echo Deleting superfluous files ...
   ${XWIPE}                                     ${INSTAPP}.RO350Hook.Boot.Tasks.!ROMPatch ${WFLAGS} # Now in PreDesk
   ${XWIPE}                                     ${INSTAPP}.RO430Hook ${WFLAGS} # Needs more testing really
   ${XWIPE}                                     ${INSTAPP}.Utils.NetBye ${WFLAGS} # Unreferenced
   ${XWIPE}                                     ${INSTAPP}.Library.Repeat ${WFLAGS} # Now in BootCommands

# Make me a !ResetBoot app
install_ResetBoot:
   ${MKDIR}                                     ${INSTAPP}.Themes
   ${CP} ${LDIR}.Morris4                        ${INSTAPP}.Themes.Morris4    ${CPFLAGS}
   ${CP} ${LDIR}.Ursula                         ${INSTAPP}.Themes.Ursula     ${CPFLAGS}
   ${CP} ${LDIR}.!Sprites                       ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
   ${CP} ${LDIR}.!Sprites11                     ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
   ${CP} ${LDIR}.!Sprites22                     ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
   ${CP} ${LDIR}.!Help                          ${INSTAPP}.!Help ${CPFLAGS}
   ${CP} ${LDIR}.!Run                           ${INSTAPP}.!Run ${CPFLAGS}
   ${CP} ${RDIR}.!Boot                          ${INSTAPP}.!Boot ${CPFLAGS}
   ${CP} ${RDIR}.!RunImage                      ${INSTAPP}.!RunImage ${CPFLAGS}
   ${CP} ${LDIR}.Messages                       ${INSTAPP}.Messages ${CPFLAGS}
   ${MKDIR}                                     ${INSTAPP}.Choices
   ${CHMOD} -R 444 ${INSTAPP}.*
   ${CHMOD} -R 744 ${INSTAPP}.Choices

# Little tiddlers
install_FreePool: Utils.FreePool
   ${CP} Utils.FreePool ${INSTDIR}.FreePool ${CPFLAGS}

install_Do: Library.Do
   ${CP} Library.Do ${INSTDIR}.Do ${CPFLAGS}

install_IfThere: Library.IfThere
   ${CP} Library.IfThere ${INSTDIR}.IfThere ${CPFLAGS}

#---------------------------------------------------------------------------
# Manual cleanup:
clean:
   ${XWIPE} Boot.TmpRun ${WFLAGS}
   ${XWIPE} ArmBoot.TmpRun ${WFLAGS}
   ${XWIPE} ShareBoot.TmpRun ${WFLAGS}
   ${XWIPE} Utils.BootVars ${WFLAGS}
   ${XWIPE} Source.BootVars.o.main ${WFLAGS}
   ${XWIPE} Library.Do ${WFLAGS}
   ${XWIPE} Source.Do.o ${WFLAGS}
   ${XWIPE} Library.PowerOff ${WFLAGS}
   ${XWIPE} Source.PowerOff.o ${WFLAGS}
   ${XWIPE} Library.SafeLogon ${WFLAGS}
   ${XWIPE} Source.SafeLogon.o.main ${WFLAGS}
   ${XWIPE} Library.IfThere ${WFLAGS}
   ${XWIPE} Source.IfThere.o ${WFLAGS}
   ${XWIPE} Configure.ClrMonitor ${WFLAGS}
   ${XWIPE} Source.ClrMonitor.o.main ${WFLAGS}
   ${XWIPE} Utils.FreePool ${WFLAGS}
   ${XWIPE} Source.FreePool.o ${WFLAGS}
   ${XWIPE} RO350Hook.Boot.PreDesk.MemFix ${WFLAGS}
   ${XWIPE} Source.MemFix.o ${WFLAGS}
   ${XWIPE} RO350Hook.Boot.PreDesk.WimpUtils ${WFLAGS}
   ${XWIPE} Source.WimpUtils.o ${WFLAGS}
   ${XWIPE} RO350Hook.Boot.PreDesk.DPMSUtils ${WFLAGS}
   ${XWIPE} Source.DPMSUtils.o ${WFLAGS}
   ${XWIPE} RO360Hook.Boot.Tasks.~CDReinit ${WFLAGS}
   ${XWIPE} RO370Hook.Boot.Tasks.~CDReinit ${WFLAGS}
   ${XWIPE} RO400Hook.Boot.Tasks.~CDReinit ${WFLAGS}
   ${XWIPE} RO430Hook.Boot.Tasks.~CDReinit ${WFLAGS}
   ${XWIPE} Source.CDReinit.o ${WFLAGS}
   ${XWIPE} RO350Hook.Boot.PreDesk.*ROMPatch ${WFLAGS}
   ${XWIPE} RO360Hook.Boot.PreDesk.*ROMPatch ${WFLAGS}
   ${XWIPE} RO370Hook.Boot.PreDesk.*ROMPatch ${WFLAGS}
   ${XWIPE} RO400Hook.Boot.PreDesk.*ROMPatch ${WFLAGS}
   ${XWIPE} Source.ROMPatch.o ${WFLAGS}
   ${XWIPE} Source.ROMPatch.Install.ROMPatch.!RunImage ${WFLAGS}
   ${XWIPE} RO370Hook.Boot.PreDesk.Configure.BandLimit ${WFLAGS}
   ${XWIPE} RO400Hook.Boot.PreDesk.Configure.BandLimit ${WFLAGS}
   ${XWIPE} RO430Hook.Boot.PreDesk.Configure.BandLimit ${WFLAGS}
   ${XWIPE} Source.BandLimit.Source.o.BandLimit ${WFLAGS}
   @echo ${COMPONENT}: cleaned

#---------------------------------------------------------------------------
# Static dependencies:
${COMPONENT}.TmpRun: ${LDIR}.!Run
   ${AWK} -f Build:AwkVers obeymode=1 < ${LDIR}.!Run > $@
   ${SETTYPE} $@ Obey

Utils.BootVars: Source.BootVars.c.main
   ${CC} ${CFLAGS} -o Source.BootVars.o.main Source.BootVars.c.main
   ${LD} ${LDFLAGS} -o $@ Source.BootVars.o.main C:RMVersion.o.RMVersion ${SOCK4LIB} ${CLIB}
   ${SQZ} $@

Library.Do: Source.Do.Source.Do
   ${MKDIR} Source.Do.o
   ${AS} ${ASFLAGS} -o Source.Do.o.Do Source.Do.Source.Do
   ${LD} ${LDFLAGS} -bin -o $@ Source.Do.o.Do 
   ${SETTYPE} $@ Utility

Library.PowerOff: Source.PowerOff.s.PowerOff
   ${MKDIR} Source.PowerOff.o
   ${AS} ${ASFLAGS} -o Source.PowerOff.o.PowerOff Source.PowerOff.s.PowerOff 
   ${LD} ${LDFLAGS} -bin -o $@ Source.PowerOff.o.PowerOff
   ${SETTYPE} $@ Utility

Library.SafeLogon: Source.SafeLogon.o.main
   ${CC} ${CFLAGS} -o Source.SafeLogon.o.main Source.SafeLogon.c.main
   ${LD} ${LDFLAGS} -o $@ Source.SafeLogon.o.main ${OSLIB} ${CLIB}
   ${SQZ} $@

Library.IfThere: Source.IfThere.Source.IfThere
   ${MKDIR} Source.IfThere.o
   ${AS} ${ASFLAGS} -o Source.IfThere.o.IfThere Source.IfThere.Source.IfThere
   ${LD} ${LDFLAGS} -bin -o $@ Source.IfThere.o.IfThere
   ${SETTYPE} $@ Utility

Configure.ClrMonitor: Source.ClrMonitor.o.main
   ${LD} ${LDFLAGS} -o $@ Source.ClrMonitor.o.main ${OSLIB} ${CLIB}
   ${SQZ} $@

Utils.FreePool: Source.FreePool.Source.FreePool
   ${MKDIR} Source.FreePool.o
   ${AS} ${ASFLAGS} -o Source.FreePool.o.FreePool Source.FreePool.Source.FreePool
   ${LD} ${LDFLAGS} -bin -o $@ Source.FreePool.o.FreePool
   ${SETTYPE} $@ Utility

RO310Hook RO350Hook RO360Hook RO370Hook RO400Hook RO430Hook RO500Hook RO510Hook RO520Hook:
   ${MKDIR} ${INSTAPP}.$@.Apps
   ${MKDIR} ${INSTAPP}.$@.Boot
   ${MKDIR} ${INSTAPP}.$@.Res
   ${CP} $@ ${INSTAPP}.$@ ${CPFLAGS}
   ${CHMOD} -R 444 ${INSTAPP}.$@.Apps
   ${CHMOD} -R 744 ${INSTAPP}.$@.Boot
   ${CHMOD} -R 444 ${INSTAPP}.$@.Res

RO350Hook.Boot.PreDesk.DPMSUtils: Source.DPMSUtils.Sources.DPMSUtils
   ${MKDIR} Source.DPMSUtils.o
   ${MKDIR} $@
   ${AS} ${ASFLAGS} -o Source.DPMSUtils.o.DPMSUtils Source.DPMSUtils.Sources.DPMSUtils
   ${LD} ${LDFLAGS} -rmf -o $@.DPMSUtils Source.DPMSUtils.o.DPMSUtils
   ${CP} Source.DPMSUtils.Sources.!Run $@.!Run ${CPFLAGS}

RO350Hook.Boot.PreDesk.WimpUtils: Source.WimpUtils.s.WimpUtils3
   ${MKDIR} Source.WimpUtils.o
   ${MKDIR} $@
   ${AS} ${ASFLAGS} -o Source.WimpUtils.o.WimpUtils Source.WimpUtils.s.WimpUtils3
   ${LD} ${LDFLAGS} -rmf -o $@.WimpUtils Source.WimpUtils.o.WimpUtils
   ${CP} Source.WimpUtils.Sources.!Run $@.!Run ${CPFLAGS}

RO350Hook.Boot.PreDesk.MemFix: Source.MemFix.Source.MemFix
   ${MKDIR} Source.MemFix.o
   ${AS} ${ASFLAGS} -o Source.MemFix.o.MemFix Source.MemFix.Source.MemFix
   ${LD} ${LDFLAGS} -bin -o $@ Source.MemFix.o.MemFix
   ${SETTYPE} $@ Utility

RO350Hook.Boot.PreDesk.ROMPatch RO360Hook.Boot.PreDesk.ROMPatch RO370Hook.Boot.PreDesk.ROMPatch RO400Hook.Boot.PreDesk.ROMPatch:
   ${MKDIR} Source.ROMPatch.o
   ${CC} ${CFLAGS} -ISource.ROMPatch -o Source.ROMPatch.o.rompatch Source.ROMPatch.c.rompatch
   ${AS} ${ASFLAGS} -o Source.ROMPatch.o.asmutils Source.ROMPatch.s.asmutils
   ${AS} ${ASFLAGS} -o Source.ROMPatch.o.module Source.ROMPatch.s.module
   ${LD} ${LDFLAGS} -aif -o Source.ROMPatch.Install.ROMPatch.!RunImage Source.ROMPatch.o.rompatch Source.ROMPatch.o.asmutils Source.ROMPatch.o.module ${CLIB}
   ${SQZ} Source.ROMPatch.Install.ROMPatch.!RunImage
   ${CP} Source.ROMPatch.Install $@.^ ${CPFLAGS}

RO360Hook.Boot.Tasks.~CDReinit RO370Hook.Boot.Tasks.~CDReinit RO400Hook.Boot.Tasks.~CDReinit RO430Hook.Boot.Tasks.~CDReinit:
   ${MKDIR} Source.CDReinit.o
   ${AS} ${ASFLAGS} -o Source.CDReinit.o.CDReinit Source.CDReinit.s.CDReinit 
   ${LD} ${LDFLAGS} -bin -o $@ Source.CDReinit.o.CDReinit
   ${SETTYPE} $@ Utility

RO370Hook.Boot.PreDesk.Configure.BandLimit RO400Hook.Boot.PreDesk.Configure.BandLimit RO430Hook.Boot.PreDesk.Configure.BandLimit: Source.BandLimit.Source.c.BandLimit
   ${CC} ${CFLAGS} -o Source.BandLimit.Source.o.BandLimit Source.BandLimit.Source.c.BandLimit
   ${LD} ${LDFLAGS} -o $@ Source.BandLimit.Source.o.BandLimit ${CLIB}
   ${SQZ} $@

#---------------------------------------------------------------------------
# Dynamic dependencies:

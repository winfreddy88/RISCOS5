# Copyright 2009 Castle Technology Ltd
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
# Makefile for !Boot.Resources.!+Resource application

COMPONENT = ResApp
TARGET   ?= !${COMPONENT}

include StdTools

VIAFILE   = ViaFiles.${RESMOD}
INSTAPP   = ${INSTDIR}.${TARGET}
MODFILE   = ${INSTAPP}.${RESMOD}

clean:
	@echo $@: ${COMPONENT}: nothing to do

install: install_${RESMOD}
	@echo $@: ${COMPONENT}: installed ${RESMOD}

install_:
	${MKDIR} ${INSTAPP}
	${CP} Resources ${INSTAPP} ${CPFLAGS}

install_WimpPool install_WindowTools: VersionNum
	@Set RemoteRes$Path ^.^.Desktop.Wimp.<LocalRes$Path>
	${GETVERSION} ResApp$BuildV ResApp$FullV ResApp$Date
	${DO} ${MODGEN} -date "<ResApp$Date>" ${MODFILE} ${RESMOD} ${RESMOD} <ResApp$BuildV> -via ${VIAFILE}
	${MODSQZ} ${MODSQZFLAGS} ${MODFILE}

install_PaintPool: VersionNum
	@Set RemoteRes$Path ^.^.Apps.Paint.<LocalRes$Path>
	${GETVERSION} ResApp$BuildV ResApp$FullV ResApp$Date
	${DO} ${MODGEN} -date "<ResApp$Date>" ${MODFILE} ${RESMOD} ${RESMOD} <ResApp$BuildV> -via ${VIAFILE}
	${MODSQZ} ${MODSQZFLAGS} ${MODFILE}

install_DrawPool: VersionNum
	@Set RemoteRes$Path ^.^.Apps.Draw.<LocalRes$Path>
	${GETVERSION} ResApp$BuildV ResApp$FullV ResApp$Date
	${DO} ${MODGEN} -date "<ResApp$Date>" ${MODFILE} ${RESMOD} ${RESMOD} <ResApp$BuildV> -via ${VIAFILE}
	${MODSQZ} ${MODSQZFLAGS} ${MODFILE}

# Dynamic dependencies:

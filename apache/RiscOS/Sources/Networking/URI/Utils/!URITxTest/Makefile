# Copyright 2000 Pace Micro Technology plc
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
# Project:   URITxTest


# Toolflags:
CCflags = -c -wp -depend !Depend -IC: -throwback
C++flags = -c -depend !Depend -IC: -throwback
Linkflags = -aif -c++ -o $@
ObjAsmflags = -throwback -NoCache -depend !Depend
CMHGflags = -depend !Depend -throwback -IC:
LibFileflags = -c -o $@
Squeezeflags = -o $@

# Final targets:
!RunImage:   o.Error o.Main C:o.URI o.dirs\
        C:o.Stubs C:tboxlibs.o.eventlib \
        C:tboxlibs.o.eventlibm C:tboxlibs.o.toolboxlib \
        C:tboxlibs.o.wimplib
        Link $(Linkflags) o.Error o.Main \
        C:o.URI C:o.Stubs \
        C:tboxlibs.o.eventlib C:tboxlibs.o.eventlibm \
        C:tboxlibs.o.toolboxlib C:tboxlibs.o.wimplib

clean:
        x wipe o ~c~v
        -delete !RunImage

o.dirs:
        cdir o
        create o.dirs

# Static dependencies:
o.Error:   c.Error
           cc $(ccflags) -o o.Error c.Error
o.Main:    c.Main
           cc $(ccflags) -o o.Main c.Main

# Dynamic dependencies:

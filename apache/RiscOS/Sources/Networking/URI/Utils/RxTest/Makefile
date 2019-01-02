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
# Project:   URITest


# Toolflags:
CCflags = -c -wp -depend !Depend -IC: -throwback
C++flags = -c -depend !Depend -IC: -throwback
Linkflags = -aif -c++ -o $@
ObjAsmflags = -throwback -NoCache -depend !Depend
CMHGflags = -depend !Depend -throwback -IC:
LibFileflags = -c -o $@
Squeezeflags = -o $@


# Final targets:
URIRxTest:   @.o.URIRxTest C:o.URI o.dirs\
        C:o.Stubs C:tboxlibs.o.wimplib
        Link $(Linkflags) @.o.URIRxTest C:o.URI \
        C:o.stubs C:tboxlibs.o.wimplib

clean:
        x wipe o ~c~v
        -delete URIRxTest

o.dirs:
        cdir o
        create o.dirs

# Static dependencies:
@.o.URIRxTest:   @.c.URIRxTest
        cc $(ccflags) -o @.o.URIRxTest @.c.URIRxTest

# Dynamic dependencies:

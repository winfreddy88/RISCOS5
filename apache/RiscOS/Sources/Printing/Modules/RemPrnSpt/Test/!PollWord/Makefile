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
# Project:   PollTest


# Toolflags:
CCflags = -c -depend !Depend -throwback -IC: -DDEBUG
Linkflags = -o $@
ObjAsmflags = -depend !Depend -ThrowBack -Stamp -quit -CloseExec
CMHGflags = 
LibFileflags = -c -o $@
Squeezeflags = -o $@
AAsmflags = -depend !Depend -quit -CloseExec -To $@ -From


# Final targets:
@.!RunImage:   @.o.Debug @.o.WimpTask SCSI::Raptor.$.!DDE.Clib.o.Stubs 
        link $(linkflags) @.o.Debug @.o.WimpTask \
        SCSI::Raptor.$.!DDE.Clib.o.Stubs 


# User-editable dependencies:

# Static dependencies:
@.o.Debug:   @.c.Debug
        cc $(ccflags) -o @.o.Debug @.c.Debug 
@.o.WimpTask:   @.c.WimpTask
        cc $(ccflags) -o @.o.WimpTask @.c.WimpTask 


# Dynamic dependencies:
o.Debug:	c.Debug
o.Debug:	C:h.swis
o.Debug:	C:h.kernel
o.WimpTask:	c.WimpTask
o.WimpTask:	C:h.kernel
o.WimpTask:	C:h.swis
o.WimpTask:	h.WimpTask
o.WimpTask:	h.debug

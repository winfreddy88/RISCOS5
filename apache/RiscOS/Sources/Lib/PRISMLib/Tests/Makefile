# Copyright 2005 Castle Technology Ltd
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
# Makefile for PLTests
# ====================
#
# -- Editor directives: StrongED ----------------------------------------------
#
# StrongED$Mode      = Make
# StrongED$WrapWidth = Line
# StrongED$FoldParm1 = ( "# -- ", "# -----", StartOfLine, case )


# -----------------------------------------------------------------------------
# -- Change List --------------------------------------------------------------
#
# Date		Name	Description
# ====		====	===========
# 2005-05-06	ADH	Created


# -----------------------------------------------------------------------------
# -- Program-specific options--------------------------------------------------

COMPONENT	 = PLTests
CFLAGS		 = ${THROWBACK} -Wpe
LIBS		+= C:PRISMLib.o.PRISMLib
DBG_LIBS	+= C:PRISMLib.o.PRISMLib TCPIPLibs:o.socklib5

# -----------------------------------------------------------------------------
# -- Standard inclusions ------------------------------------------------------

include Makefiles:StdTools
include Makefiles:AppStdRule
include Makefiles:AppLibs
include Makefiles:CApp


# -----------------------------------------------------------------------------

# Dynamic dependencies:
od.PLTests:	c.PLTests
od.PLTests:	C:PRISMLib.h.PRISMLib
od.PLTests:	C:PRISMLib.h.Errors
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.Messages
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.Clients
od.PLTests:	C:PRISM.h.PRISM
od.PLTests:	C:PRISMLib.h.Locks
od.PLTests:	C:PRISMLib.h.Interrupts
od.PLTests:	C:h.swis
od.PLTests:	C:PRISMLib.h.Timers
od.PLTests:	C:PRISMLib.h.Mechanism
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISM.h.PRISM
od.PLTests:	C:PRISMLib.h.Handles
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.Clients
od.PLTests:	C:PRISMLib.h.JobQueue
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.RLists
od.PLTests:	C:PRISMLib.h.FuncTypes
od.PLTests:	C:PRISMLib.h.NRLists
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.NRArrays
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISMLib.h.FuncTypes
od.PLTests:	C:PRISMLib.h.TLV
od.PLTests:	C:h.kernel
od.PLTests:	C:PRISM.h.PRISM
od.PLTests:	C:PRISMLib.h.FuncTypes
o.PLTests:	c.PLTests
o.PLTests:	C:PRISMLib.h.PRISMLib
o.PLTests:	C:PRISMLib.h.Errors
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.Messages
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.Clients
o.PLTests:	C:PRISM.h.PRISM
o.PLTests:	C:PRISMLib.h.Locks
o.PLTests:	C:PRISMLib.h.Interrupts
o.PLTests:	C:h.swis
o.PLTests:	C:PRISMLib.h.Timers
o.PLTests:	C:PRISMLib.h.Mechanism
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISM.h.PRISM
o.PLTests:	C:PRISMLib.h.Handles
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.Clients
o.PLTests:	C:PRISMLib.h.JobQueue
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.RLists
o.PLTests:	C:PRISMLib.h.FuncTypes
o.PLTests:	C:PRISMLib.h.NRLists
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.NRArrays
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISMLib.h.FuncTypes
o.PLTests:	C:PRISMLib.h.TLV
o.PLTests:	C:h.kernel
o.PLTests:	C:PRISM.h.PRISM
o.PLTests:	C:PRISMLib.h.FuncTypes

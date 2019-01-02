# 
# CDDL HEADER START
# 
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "Licence").
# You may not use this file except in compliance with the Licence.
# 
# You can obtain a copy of the licence at
# RiscOS/Sources/ThirdParty/Endurance/Lib/DThreads/LICENCE.
# See the Licence for the specific language governing permissions
# and limitations under the Licence.
# 
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the Licence file. If applicable, add the
# following below this CDDL HEADER, with the fields enclosed by
# brackets "[]" replaced with your own identifying information:
# Portions Copyright [yyyy] [name of copyright owner]
# 
# CDDL HEADER END
# 
# 
# Copyright 2007 Endurance Technology Ltd.  All rights reserved.
# Use is subject to license terms.
# 
# Makefile for DThreads
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date        Name         Description
# ----        ----         -----------
# 21-Jun-2007 BJGA         Created.
#

COMPONENT  = Dynamic Area Threads
TARGET     = DThreads
HDRS       = DThreads
OBJS       = CGlue CStart
LIBRARY    = no-app-lib
LIBRARYD   = no-app-debug-lib
LIBRARYZM  = ${TARGET}
LIBRARYDZM = ${TARGET}D
LIBRARIES  = ${LIBRARYZM} ${LIBRARYDZM}
CFLAGS     = -ff -fah

include StdTools
include StdRules
include DbgRules
include CLibrary

# Dynamic dependencies:

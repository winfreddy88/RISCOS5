# Copyright 2012 Castle Technology Ltd
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
# Makefile for Squish
#

#
# Program specific options:
#
COMPONENT  = Squish
MSGVERSION = ${AWK} -f Build:AwkVers

include StdTools

SQFLAGS = -nolist

FILES  =\
 squished.${COMPONENT}

#
# Generic build rules:
#
all: ${FILES}
     @${ECHO} ${COMPONENT}: all build complete

install: ${FILES}
         ${CP} squished.${COMPONENT} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
         @${ECHO} ${COMPONENT}: installed

clean:
       ${XWIPE} squished ${WFLAGS}
       ${XWIPE} crunched ${WFLAGS}
       ${XWIPE} n ${WFLAGS}
       @${ECHO} ${COMPONENT}: cleaned

#
# Static dependencies:
#
                     
squished.${COMPONENT}: crunched.${COMPONENT} bas.Keep
        ${MKDIR} squished
        ${SQUISH} ${SQFLAGS} -keep bas.Keep -from crunched.${COMPONENT} -to $@

crunched.${COMPONENT}: n.${COMPONENT}
        ${MKDIR} crunched
        crunch.${COMPONENT}; BASIC

n.${COMPONENT}: bas.${COMPONENT}
        ${MKDIR} n
        ${NUMBER} bas.${COMPONENT} $@

#---------------------------------------------------------------------------
# Dynamic dependencies:

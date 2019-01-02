# Makefile for GNU/readelf
#

COMPONENT ?= readelf
INSTAPP    = ${INSTDIR}${SEP}!ReadELF
OBJS       = readelf version getopt getopt1
CDEFINES   = -DHAVE_STRING_H
CINCLUDES  = -Iinclude,bfd,C:,TCPIPLibs:
INSTAPP_FILES = !Boot !Help !Run !Sprites [!Sprites22] Messages Templates readelf
INSTAPP_VERSION = Desc

include CApp

# Dynamic dependencies:

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
# Makefile for NFS
#

COMPONENT    = NFS
OBJS         = xdr_manual printfuncs chains enumdir enumdir2 \
	_Args _Close _File _Func _GBPB _GetBytes _Open _PutBytes \
	Interface Static allerrs Hourglass extensions access \
	ModuleWrap Commands nfsrw V2support memory fh3 \
	Utils Clients ChangeInfo PutBytesX pathmunge Cache \
	rquota_xdr nfs_prot_clnt nfs_prot_xdr pcnfsd_clnt pcnfsd_xdr mount_clnt mount_xdr
CMHGDEPENDS  = ModuleWrap
CMHGAUTOHDR  = NFS
CINCLUDES    = -ITCPIPLibs:
CDEFINES     = -DCOMPAT_INET4 -DPACKETSIZE_COMMAND ${OPTIONS} -Darm -DRPC_SVC=0 -DRPC_HDR=1
LIBS        += ${ASMUTILS} ${RPCLIB} ${NET4LIBS}
ASMCHDRS     = NFS
ASMHDRS      = NFS
HDRS         =
CUSTOMRES    = no

include CModule

CFLAGS      += -c90 -Wp
CDFLAGS     += -DDEBUG -DDEBUGLIB
CMHGDFLAGS   = -DDEBUG

# Extra clean to remove the RPCGENerated files
clean::
	${RM} h${SEP}rquota
	${RM} h${SEP}pcnfsd
	${RM} h${SEP}nfs_prot
	${RM} h${SEP}mount
	${RM} c${SEP}rquota_clnt
	${RM} c${SEP}rquota_xdr
	${RM} c${SEP}nfs_prot_clnt
	${RM} c${SEP}nfs_prot_xdr
	${RM} c${SEP}pcnfsd_clnt
	${RM} c${SEP}pcnfsd_xdr
	${RM} c${SEP}mount_clnt
	${RM} c${SEP}mount_xdr

# One area per function.  Helps linker throw away all the unused
# auto-generated code.
# The compiler cannot typically optimise register usage here because
# eventually all XDR related functions end up inside rpclib:xdr.c anyway.

ifeq (${MAKECMDGOALS},debug)
RPCCFLAGS   = $(filter-out ${C_NO_FNAMES},${CFLAGS}) ${CDFLAGS} -zo
else
RPCCFLAGS   = ${CFLAGS} -zo
endif
RPCGENFLAGS = -i 0 -DWANT_NFS3 -debuglib
RPCTEMPFILE = o${SEP}_tmpfile_
RPCGENHDRS  = mount.h nfs_prot.h pcnfsd.h rquota.h

rquota.h: rquota.x
	${RPCGEN} ${RPCGENFLAGS} -h -o $@ $*.x
pcnfsd.h: pcnfsd.x
	${RPCGEN} ${RPCGENFLAGS} -h -o $@ $*.x
nfs_prot.h: nfs_prot.x
	${RPCGEN} ${RPCGENFLAGS} -h -o $@ $*.x
mount.h: mount.x
	${RPCGEN} ${RPCGENFLAGS} -h -o $@ $*.x

# NOTE: nfs_prot_xdr.c defines a recursive xdr routine for the entry types.
# If used with a sufficiently large directory, this causes the SVC stack
# to overflow.  There are iterative versions in xdr_manual.c which replace
# these routines.  We use sed to alter the name of the functions in the
# code that rpcgen generates to avoid duplicate symbol definitions.

mount_clnt.c: mount.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -l -o $@ mount.x
mount_xdr.c: mount.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -c -o $@ mount.x
nfs_prot_clnt.c: nfs_prot.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -l -o $@ nfs_prot.x
nfs_prot_xdr.c: nfs_prot.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -c -o ${RPCTEMPFILE} nfs_prot.x
	${SED} "s/^xdr_entry/obs_xdr_entry/" < ${RPCTEMPFILE} > $@
	${RM} ${RPCTEMPFILE}
pcnfsd_clnt.c: pcnfsd.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -l -o $@ pcnfsd.x
pcnfsd_xdr.c: pcnfsd.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -c -o $@ pcnfsd.x
rquota_clnt.c: rquota.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -l -o $@ rquota.x
rquota_xdr.c: rquota.x ${RPCGENHDRS}
	${RPCGEN} ${RPCGENFLAGS} -c -o $@ rquota.x

od.mount_xdr o.mount_xdr: mount_xdr.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.mount_clnt o.mount_clnt: mount_clnt.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.nfs_prot_xdr o.nfs_prot_xdr: nfs_prot_xdr.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.nfs_prot_clnt o.nfs_prot_clnt: nfs_prot_clnt.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.pcnfsd_xdr o.pcnfsd_xdr: pcnfsd_xdr.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.pcnfsd_clnt o.pcnfsd_clnt: pcnfsd_clnt.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.rquota_xdr o.rquota_xdr: rquota_xdr.c
	${CC} ${RPCCFLAGS} -o $@ $*.c
od.rquota_clnt o.rquota_clnt: rquota_clnt.c
	${CC} ${RPCCFLAGS} -o $@ $*.c

# Dynamic dependencies:

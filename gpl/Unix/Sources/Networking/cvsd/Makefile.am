# Makefile.am - use automake to generate Makefile.in
# Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Arthur de Jong
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA


sbin_PROGRAMS=cvsd
sbin_SCRIPTS=cvsd-buildroot cvsd-passwd cvsd-buginfo
cvsd_SOURCES=cvsd.c aclocal.m4 \
             xmalloc.c xmalloc.h \
             cfgfile.c cfgfile.h \
             log.c log.h \
             cfg.c cfg.h
cvsd_LDADD=@LIBOBJS@

CONFIGFILE=@CONFIGFILE@

EXTRA_DIST=cvsd.conf-dist \
           getopt_long.c getopt_long.h \
           reslimit.c reslimit.h \
           daemon.c daemon.h \
           getinfos.c getinfos.h \
           debian/control debian/changelog debian/rules debian/docs \
           debian/postinst debian/postrm debian/copyright \
           debian/config debian/templates debian/cvsd.init \
           debian/cvsd.bug.script \
           debian/compat \
           debian/po/POTFILES.in \
           debian/po/templates.pot \
           debian/po/cs.po \
           debian/po/da.po \
           debian/po/de.po \
           debian/po/es.po \
           debian/po/fr.po \
           debian/po/ja.po \
           debian/po/nl.po \
           debian/po/pt_BR.po \
           debian/po/pt.po \
           debian/po/vi.po \
           cvsd.spec \
           FAQ

#  if you write a self-test script named `chk', uncomment the
#  following and add `chk' to the EXTRA_DIST list
#TESTS=chk

#  install the man pages
man_MANS=cvsd.8 cvsd-buildroot.8 cvsd.conf.5 cvsd-passwd.8 \
         cvsd-buginfo.8

#  install configuration files
install-data-local: install-configfile install-initscript

install-configfile:
	if [ ! -d $(DESTDIR)$(sysconfdir)/cvsd ]; then \
	  $(mkinstalldirs) $(DESTDIR)$(sysconfdir)/cvsd;\
	fi
	if [ ! -f $(DESTDIR)$(CONFIGFILE) ]; then \
	  $(INSTALL_DATA) $(srcdir)/cvsd.conf-dist $(DESTDIR)$(CONFIGFILE); \
	else \
	  echo "$(DESTDIR)$(CONFIGFILE) already exists, install will not overwrite"; \
	fi

install-initscript:
	if [ ! -d $(DESTDIR)$(sysconfdir)/init.d ]; then \
	  $(mkinstalldirs) $(DESTDIR)$(sysconfdir)/init.d; \
	fi
	if [ -f $(DESTDIR)$(sysconfdir)/init.d/cvsd ]; then \
	  echo "$(DESTDIR)$(sysconfdir)/init.d/cvsd already exists, overwriting"; \
	fi
	$(INSTALL_SCRIPT) cvsd.init $(DESTDIR)$(sysconfdir)/init.d/cvsd

#  targets for debian package
deb: distdir
	cd $(distdir) && \
	  fakeroot debian/rules binary
	rm -rf $(distdir)
signeddeb: distdir
	cd $(distdir) && \
	  debuild
	rm -rf $(distdir)

# targets for redhat rpm
rpm: dist
	rpmbuild -ta --clean cvsd-$(VERSION).tar.gz
signedrpm:
	rpmbuild -ta --clean --sign cvsd-$(VERSION).tar.gz

# clean extra files
DISTCLEANFILES = *-stamp \
                 cvsd_$(VERSION).tar.gz \
                 cvsd_$(VERSION).dsc cvsd_$(VERSION)_*.changes \
                 cvsd_$(VERSION)_*.deb cvsd_$(VERSION)_*.build \
                 cvsd-$(VERSION).tar.gz

changelog:
	cvs2cl --window 3600 --accum --prune

faq:
	( echo '' ; \
	  echo 'Frequently Asked Questions for cvsd' ; \
	  echo '===================================' ; \
	  echo '' ; \
	  echo 'the latest version of this FAQ can be found at' ; \
	  echo 'http://ch.tudelft.nl/~arthur/cvsd/faq.html' ; \
	  lynx -dump -nolist http://ch.tudelft.nl/~arthur/cvsd/faq.html | \
	    tail -n +11 | head -n -5 | \
	    sed 's/^   //' ) > FAQ

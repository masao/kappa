## Process this file with automake to produce Makefile.in

## This is a part of kappa
## Copyright (C) 1999, Yuka Egusa, Masao Takaku. All rights reserved.

AUTOMAKE_OPTIONS = no-dependencies

bin_SCRIPTS = kappa
bin_PROGRAMS = kappa.bin
kappa_bin_SOURCES = client.c

pkgdata_DATA = client.tcl opensite default.bib

EXTRA_DIST = kappa client.tcl.in opensite default.bib

# YAZ(Yet Another Toolkit) directory
YAZDIR=@YAZDIR@

# Tcl/Tk Includes & Libraries
TCLINC=@TCLINC@
TCLLIB=@TCLLIB@

TKINC=@TKINC@
TKLIB=@TKLIB@

# Compiler options
INCLUDE=-I$(YAZDIR)/include $(TCLINC) $(TKINC)
DEFS=-DCCL2RPN=1 $(INCLUDE)

kappa_bin_LDADD=$(YAZDIR)/lib/libyaz.a $(YAZDIR)/lib/ccl.a $(TCLLIB) $(TKLIB)

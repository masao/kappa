# Copyright (C) 1995-1998, Index Data I/S 
# All rights reserved.
# Sebastian Hammer, Adam Dickmeiss
# $Id$

# For Tcl/Tk
TCLTK_INC=/usr/local/include
TCLTK_LIBDIR=/usr/local/lib
TCLTK_LIBS=-ltk4.2jp -ltcl7.6jp -lX11 -lm

# For YAZ
YAZDIR=../yaz-1.4pl2
LIBDIR=$(YAZDIR)/lib

#LIBMOSI=../../xtimosi/src/libmosi.a $(LIBDIR)/librfc.a

SHELL=/bin/sh
INCLUDE=-I$(YAZDIR)/include -I. -I../../xtimosi/src -I$(TCLTK_INC)
LIBINCLUDE=-L$(LIBDIR) -L$(TCLTK_LIBDIR)
DEFS=$(INCLUDE) $(CDEFS) -DCCL2RPN=1
LIBS=$(LIBDIR)/libasn.a $(LIBDIR)/libodr.a \
  $(LIBDIR)/libcomstack.a $(LIBDIR)/ccl.a $(LIBMOSI) $(LIBDIR)/libutil.a
CPP=$(CC) -E
PROG=client
PROGO=client.o

ELIBS=

CHMOD=/bin/chmod

all: kappa

kappa: $(PROG)

$(PROG): $(LIB) $(PROGO) $(LIBS) version.h
	$(CC) $(CFLAGS) $(LIBINCLUDE) -o $(PROG) $(PROGO) $(LIBS) $(ELIBS) $(TCLTK_LIBS)

alll:

$(LIBDIR):
	mkdir $(LIBDIR)

.c.o:
	$(CC) -c -g $(DEFS) $(CFLAGS) $<

clean:
	rm -f *.[oa] *~ test core mon.out gmon.out errlist tst cli $(PROG)

depend: depend1

depend1:
	sed '/^#Depend/q' <Makefile >Makefile.tmp
	$(CPP) $(DEFS) -M *.c >>Makefile.tmp
	mv -f Makefile.tmp Makefile

depend2:
	$(CPP) $(DEFS) -M *.c >.depend	

#ifeq (.depend,$(wildcard .depend))
#include .depend
#endif

#Depend --- DOT NOT DELETE THIS LINE

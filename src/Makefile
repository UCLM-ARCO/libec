# -*- mode: makefile-gmake; coding: utf-8 -*-

FILES    = string.cc string.h logger.cc logger.h os.cc os.h \
	   ConfigParser.cc ConfigParser.h PyHandle.h \
	   PyFunctions.h PyFunctions.cc

CXXFLAGS = -Wall -ggdb -fPIC $$(python-config --includes)
LDLIBS   = $$(python-config --ldflags)

VERSION  = 1.0
SONAME   = 1

LIB      = libec


all: $(LIB).a $(LIB).so.$(VERSION)

$(LIB).a: $(FILES:%.cc=%.o)
	$(AR) rcs $@ $(filter %.o, $^)

$(LIB).so.$(VERSION): LDFLAGS = -shared -Wl,-soname=$(LIB).so.$(SONAME)
$(LIB).so.$(VERSION): $(FILES:%.cc=%.o)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $(filter %.o, $^)

install: all
	install -dv $(DESTDIR)/usr/lib $(DESTDIR)/usr/include/ec
	install -v *.so* *.a $(DESTDIR)/usr/lib
	install -v *.h $(DESTDIR)/usr/include/ec
	-ln -s libec.so.1.0 $(DESTDIR)/usr/lib/libec.so
	-ln -s libec.so.1.0 $(DESTDIR)/usr/lib/libec.so.1

clean:
	$(RM) *.so* *.a *.o *~

distclean:
check:


-include config.mk
export DESTDIR?=$(HOME)/

FILES=string.cc string.h logger.cc logger.h os.cc os.h ConfigParser.cc ConfigParser.h
CXXFLAGS=-Wall -ggdb -fPIC

VERSION=1.0
SONAME=1

LIB=libeasyc++

all: $(LIB).a $(LIB).so.$(VERSION)

$(LIB).a: $(FILES:%.cc=%.o)
	$(AR) rcs $@ $(filter %.o, $^)

$(LIB).so.$(VERSION): LDFLAGS = -shared -Wl,-soname=$(LIB).so.$(SONAME)
$(LIB).so.$(VERSION): $(FILES:%.cc=%.o)
	$(CXX) $(LDFLAGS) -o $@ $(filter %.o, $^)

install: all
	install -dv $(DESTDIR)/usr/lib $(DESTDIR)/usr/include/easyc++
	install -v *.so* *.a $(DESTDIR)/usr/lib
	install -v *.h $(DESTDIR)/usr/include/easyc++
	-ln -s libeasyc++.so.1.0 $(DESTDIR)/usr/lib/libeasyc++.so
	-ln -s libeasyc++.so.1.0 $(DESTDIR)/usr/lib/libeasyc++.so.1

clean:
	$(RM) *.so* *.a *.o *~
	$(MAKE) -C test clean



-include config.mk
export DESTDIR?=$(HOME)/

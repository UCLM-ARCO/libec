
CXXFLAGS=-I.. -g
LDFLAGS=-L.. --static
LDLIBS=-leasyc++

TESTS=$(wildcard *.cc)
TARGET=$(TESTS:%.cc=%)

all: $(TARGET)

$(TARGET): ../libeasyc++.a

clean:
	$(RM) $(TARGET) *.o *~

CC := gcc
CPP := g++
RM := rm -f

CFLAGS := -Wall -pedantic -std=c99 -I. -DHAVE_CONFIG_H
CPPFLAGS := -Wall -pedantic -std=gnu++0x -I. -DHAVE_CONFIG_H

MINIZIP_BIN := libminizip.a
MINIZIP_OBJS :=
MINIZIP_OBJS += ioapi.o
MINIZIP_OBJS += iowin32.o
MINIZIP_OBJS += mztools.o
MINIZIP_OBJS += unzip.o
MINIZIP_OBJS += zip.o

MINIZIP_OBJS += miniunz.o
MINIZIP_OBJS += minizip.o

all: $(MINIZIP_BIN)

$(MINIZIP_BIN) : $(MINIZIP_OBJS)
	ar r $@ $^
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $^

%.o : %.cc
	$(CPP) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean

clean:
	$(RM) $(MINIZIP_BIN) $(MINIZIP_OBJS)

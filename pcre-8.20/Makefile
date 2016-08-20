CC := gcc
CPP := g++
RM := rm -f

CFLAGS := -Wall -pedantic -std=c99 -I. -DHAVE_CONFIG_H
CPPFLAGS := -Wall -pedantic -std=gnu++0x -I. -DHAVE_CONFIG_H

PCRE_BIN := libpcre.a
PCRE_OBJS += pcre_compile.o 
PCRE_OBJS += pcre_config.o 
PCRE_OBJS += pcre_dfa_exec.o 
PCRE_OBJS += pcre_exec.o 
PCRE_OBJS += pcre_fullinfo.o 
PCRE_OBJS += pcre_get.o 
PCRE_OBJS += pcre_globals.o 
PCRE_OBJS += pcre_info.o 
PCRE_OBJS += pcre_jit_compile.o 
PCRE_OBJS += pcre_maketables.o 
PCRE_OBJS += pcre_newline.o 
PCRE_OBJS += pcre_ord2utf8.o 
PCRE_OBJS += pcre_refcount.o 
PCRE_OBJS += pcre_study.o 
PCRE_OBJS += pcre_tables.o 
PCRE_OBJS += pcre_try_flipped.o 
PCRE_OBJS += pcre_ucd.o 
PCRE_OBJS += pcre_valid_utf8.o 
PCRE_OBJS += pcre_version.o 
PCRE_OBJS += pcre_xclass.o 
PCRE_OBJS += pcre_chartables.o

PCRECPP_BIN := libpcrecpp.a
PCRECPP_OBJS := 
PCRECPP_OBJS += pcrecpp.o 
PCRECPP_OBJS += pcre_scanner.o 
PCRECPP_OBJS += pcre_stringpiece.o

all: $(PCRE_BIN) $(PCRECPP_BIN)

$(PCRE_BIN) : $(PCRE_OBJS)
	ar r $@ $^
	ranlib $@

$(PCRECPP_BIN) : $(PCRECPP_OBJS)
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
	$(RM) $(PCRE_BIN) $(PCRE_OBJS)
	$(RM) $(PCRECPP_BIN) $(PCRECPP_OBJS)

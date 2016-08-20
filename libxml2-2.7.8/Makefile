CC := gcc
CPP := g++
RM := rm -f

INC := 
INC += -DLIBXML_STATIC
INC += -DHAVE_WIN32_THREADS -D_REENTRANT
INC += -I. -I./include -DHAVE_CONFIG_H 

CFLAGS := -Wall -pedantic -std=c99 $(INC)
CPPFLAGS := -Wall -pedantic -std=gnu++0x $(INC)

XML2_BIN := libxml2.a
XML2_OBJS :=
XML2_OBJS += SAX.o
XML2_OBJS += entities.o
XML2_OBJS += encoding.o
XML2_OBJS += error.o
XML2_OBJS += parserInternals.o
XML2_OBJS += parser.o
XML2_OBJS += tree.o
XML2_OBJS += hash.o
XML2_OBJS += list.o
XML2_OBJS += xmlIO.o
XML2_OBJS += xmlmemory.o
XML2_OBJS += uri.o
XML2_OBJS += valid.o
XML2_OBJS += xlink.o
XML2_OBJS += HTMLparser.o
XML2_OBJS += HTMLtree.o
XML2_OBJS += debugXML.o
XML2_OBJS += xpath.o
XML2_OBJS += xpointer.o
XML2_OBJS += xinclude.o
XML2_OBJS += nanohttp.o
XML2_OBJS += nanoftp.o
XML2_OBJS += DOCBparser.o
XML2_OBJS += catalog.o
XML2_OBJS += globals.o
XML2_OBJS += threads.o
XML2_OBJS += c14n.o
XML2_OBJS += xmlstring.o
XML2_OBJS += xmlregexp.o
XML2_OBJS += xmlschemas.o
XML2_OBJS += xmlschemastypes.o
XML2_OBJS += xmlunicode.o
XML2_OBJS += xmlreader.o
XML2_OBJS += relaxng.o
XML2_OBJS += dict.o
XML2_OBJS += SAX2.o
XML2_OBJS += xmlwriter.o
XML2_OBJS += legacy.o
XML2_OBJS += chvalid.o
XML2_OBJS += pattern.o
XML2_OBJS += xmlsave.o
XML2_OBJS += xmlmodule.o
XML2_OBJS += schematron.o

all: $(XML2_BIN)

$(XML2_BIN) : $(XML2_OBJS)
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
	$(RM) $(XML2_BIN) $(XML2_OBJS)

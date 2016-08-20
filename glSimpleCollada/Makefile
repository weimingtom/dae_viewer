CC := gcc
CPP := g++
RC := windres
RM = rm -f

INC := 
INC += -I../collada-dom-2.3.1/dom/include 
INC += -I../collada-dom-2.3.1/dom/include/1.4 
INC += -I../pcre-8.20
INC += -I../boost_1_47_0 
INC += -I../libxml2-2.7.8/include -DLIBXML_STATIC
INC += -I../minizip 
INC += -I../glut/include -DGLUT_STATIC

CFLAGS := -Wall -pedantic -ansi -std=c99 $(INC)
CPPFLAGS := -Wall -pedantic -std=gnu++0x $(INC)

LDFLAGS	:= 
LDFLAGS	+= -L../collada-dom-2.3.1/dom -lcollada14dom 
LDFLAGS	+= -L../pcre-8.20 -lpcrecpp -lpcre 
LDFLAGS	+= -L../boost_1_47_0 -lboost_system -lboost_filesystem 
LDFLAGS	+= -L../libxml2-2.7.8 -lxml2 
LDFLAGS	+= -L../minizip -lminizip 
LDFLAGS	+= -lz
LDFLAGS	+= -L../glut/lib -lglut32
LDFLAGS	+= -lglaux -lglu32 -lopengl32
LDFLAGS	+= -lwinmm -lgdi32 -lcomdlg32 -lws2_32

OBJS := 
OBJS += TGATexture.o

# Rendering
LIB_BIN := objview.a
BINS := glSimpleCollada.exe test.exe

all: $(BINS)

$(LIB_BIN) : $(OBJS)
	ar r $@ $(OBJS)
	ranlib $@

test.exe : test.o
	$(CPP) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) 

glSimpleCollada.exe : main.o $(LIB_BIN)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) 

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean test

clean:
	$(RM) $(OBJS) $(LIB_BIN) $(BINS) *.o 
	$(RM) simple.dae

test:
	./glSimpleCollada.exe

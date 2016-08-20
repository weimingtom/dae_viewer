CPP := g++
RM := rm -f

CPPFLAGS := -Wall -pedantic -std=gnu++0x -I.

SYS_BIN := libboost_system.a
SYS_OBJS := libs/system/src/error_code.o

FIL_BIN := libboost_filesystem.a
FIL_OBJS := 
FIL_OBJS += libs/filesystem/v2/src/v2_operations.o
FIL_OBJS += libs/filesystem/v2/src/v2_path.o
FIL_OBJS += libs/filesystem/v2/src/v2_portability.o
FIL_OBJS += libs/filesystem/v3/src/operations.o
FIL_OBJS += libs/filesystem/v3/src/path.o
FIL_OBJS += libs/filesystem/v3/src/portability.o
FIL_OBJS += libs/filesystem/v3/src/path_traits.o
FIL_OBJS += libs/filesystem/v3/src/unique_path.o
FIL_OBJS += libs/filesystem/v3/src/windows_file_codecvt.o
FIL_OBJS += libs/filesystem/v3/src/codecvt_error_category.o
#FIL_OBJS += libs/filesystem/v3/src/utf8_codecvt_facet.o

all: $(SYS_BIN) $(FIL_BIN)

$(SYS_BIN) : $(SYS_OBJS)
	ar r $@ $^
	ranlib $@

$(FIL_BIN) : $(FIL_OBJS)
	ar r $@ $^
	ranlib $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean

clean:
	$(RM) $(SYS_BIN) $(SYS_OBJS)
	$(RM) $(FIL_BIN) $(FIL_OBJS)

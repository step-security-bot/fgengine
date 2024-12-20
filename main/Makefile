SRCDIR                = .
SUBDIRS               =
DLLS                  =
LIBS                  =
EXES                  = main.exe



### Common settings

CEXTRA                =
CXXEXTRA              =
RCEXTRA               =
DEFINES               =
INCLUDE_PATH          =
DLL_PATH              =
DLL_IMPORTS           =
LIBRARY_PATH          =
LIBRARIES             = -lSDL3


### main.exe sources and settings

main_exe_MODULE       = main.exe
main_exe_C_SRCS       = src/main.c
main_exe_CXX_SRCS     =
main_exe_RC_SRCS      =
main_exe_LDFLAGS      =
main_exe_ARFLAGS      =
main_exe_DLL_PATH     =
main_exe_DLLS         =
main_exe_LIBRARY_PATH =
main_exe_LIBRARIES    =

main_exe_OBJS         = $(main_exe_C_SRCS:.c=.o) \
			$(main_exe_CXX_SRCS:.cpp=.o) \
			$(main_exe_RC_SRCS:.rc=.res)



### Global source lists

C_SRCS                = $(main_exe_C_SRCS)
CXX_SRCS              = $(main_exe_CXX_SRCS)
RC_SRCS               = $(main_exe_RC_SRCS)


### Tools

CC = gcc
CXX = g++
RC = rcc
AR = ar


### Generic targets

all: $(SUBDIRS) $(DLLS:%=%.so) $(LIBS) $(EXES)

### Build rules

.PHONY: all clean dummy

$(SUBDIRS): dummy
	@cd $@ && $(MAKE)

# Implicit rules

.SUFFIXES: .cpp .cxx .rc .res
DEFINCL = $(INCLUDE_PATH) $(DEFINES) $(OPTIONS)

.c.o:
	$(CC) -c $(CFLAGS) $(CEXTRA) $(DEFINCL) -o $@ $<

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(CXXEXTRA) $(DEFINCL) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(CXXEXTRA) $(DEFINCL) -o $@ $<

.rc.res:
	$(RC) $(RCFLAGS) $(RCEXTRA) $(DEFINCL) -fo$@ $<

# Rules for cleaning

CLEAN_FILES     = y.tab.c y.tab.h lex.yy.c core *.orig *.rej \
                  \\\#*\\\# *~ *% .\\\#*

clean:: $(SUBDIRS:%=%/__clean__) $(EXTRASUBDIRS:%=%/__clean__)
	$(RM) $(CLEAN_FILES) $(RC_SRCS:.rc=.res) $(C_SRCS:.c=.o) $(CXX_SRCS:.cpp=.o)
	$(RM) $(DLLS:%=%.so) $(LIBS) $(EXES) $(EXES:%=%.so)

$(SUBDIRS:%=%/__clean__): dummy
	cd `dirname $@` && $(MAKE) clean

$(EXTRASUBDIRS:%=%/__clean__): dummy
	-cd `dirname $@` && $(RM) $(CLEAN_FILES)

### Target specific build rules
DEFLIB = $(LIBRARY_PATH) $(LIBRARIES) $(DLL_PATH) $(DLL_IMPORTS:%=-l%)

$(main_exe_MODULE): $(main_exe_OBJS)
	$(CC) $(main_exe_LDFLAGS) -o $@ $(main_exe_OBJS) $(main_exe_LIBRARY_PATH) $(main_exe_DLL_PATH) $(DEFLIB) $(main_exe_DLLS:%=-l%) $(main_exe_LIBRARIES:%=-l%)



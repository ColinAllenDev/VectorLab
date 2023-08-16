## Compiler Configuration 
CPPC 				= g++
STANDARD_FLAGS		= -std=c++14
WARNING_FLAGS		= -Wall
DEBUG_FLAGS		 	= -g3
OPT_FLAGS			= -O0
COMPILE_ONLY_FLAG	= -c

## Workspace Paths
WORKSPACE_ROOT 	= $(CURDIR)
VL_ROOT 		= $(WORKSPACE_ROOT)VectorLab/
VL_SRC 			= $(VL_ROOT)src/
VL_BIN			= $(VL_ROOT)bin/
VL_INT			= $(VL_ROOT)int/
APP_ROOT 		= $(WORKSPACE_ROOT)Sandbox/
APP_SRC 		= $(APP_ROOT)src/
APP_BIN			= $(APP_ROOT)bin/
APP_INT			= $(APP_ROOT)int/

## VectorLab - Static Library 
VL_CPP_FLAGS = $(STANDARD_FLAGS) $(DEBUG_FLAGS) $(OPT_FLAGS) $(COMPILE_ONLY_FLAG) $(WARNING_FLAGS)
VL_FNAME = libVectorLab.a
VL_SRCS = $(VL_SRC)$(wildcard **/*.cpp)
VL_OBJS = $(VL_INT)$(wildcard *.o)

$(VL_INT)%.o: %.cpp
	g++ -c -g $< -o $@
$(VL_BIN)libVectorLab.a: $(VL_OBJS)

## Sandbox - Application
APP_INCLUDES = -I$(APP_SRC) -I$(VL_SRC)
APP_SOURCES	 = $(APP_SRC)$(wildcard **/*.cpp)
APP_OBJS	 = $(APP_BIN)
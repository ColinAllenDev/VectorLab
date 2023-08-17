## Compiler Configuration 
CPPC 				= g++
STANDARD_FLAGS		= -std=c++14
WARNING_FLAGS		= -Wall
DEBUG_FLAGS		 	= -g3
OPT_FLAGS			= -O0
COMPILE_ONLY_FLAG	= -c

## VectorLab - Static Library 
VL_FNAME = libVectorLab.a
VL_CPP_FLAGS = $(STANDARD_FLAGS) $(DEBUG_FLAGS) $(OPT_FLAGS) $(WARNING_FLAGS)

VL_SRC_PATH = VectorLab/src
VL_OBJ_PATH = VectorLab/build
VL_BIN_PATH = VectorLab/bin
VL_VENDOR_PATH = VectorLab/vendor

VL_INCLUDES = -I$(VL_VENDOR_PATH)/spdlog/include -I$(VL_VENDOR_PATH)/bgfx/include \
			  -I$(VL_VENDOR_PATH)/bx/include -I$(VL_VENDOR_PATH)/bimg/include
# TODO: Add platform-specific libraries 
VL_LIBS 	= -L$(VL_VENDOR_PATH)/bgfx/.build/linux64_gcc/bin/bgfx-shared-libRelease.so \
			  -Lfmt -LSDL2

VL_SRCS = $(wildcard $(VL_SRC_PATH)/**/*.cpp)
VL_OBJS = $(patsubst $(wildcard $(VL_SRC_PATH)/**/)%.cpp, VectorLab/build/%.o, $(VL_SRCS))

all: $(VL_BIN_PATH)/$(VL_FNAME)

VectorLab/bin/$(VL_FNAME): $(VL_OBJS)
#	g++ $(VL_INCLUDES) $(VL_LIBS) $(VL_CPP_FLAGS) $^ -o $@

VectorLab/build/%.o: $(wildcard $(VL_SRC_PATH)/**/)%.cpp
	g++ $(VL_INCLUDES) $(VL_CPP_FLAGS) $(COMPILE_ONLY_FLAG) $< -o $@

clean:
	@rm -rf VectorLab/bin/* VectorLab/build/*
## Sandbox - Application
#APP_INCLUDES = -I$(APP_SRC) -I$(VL_SRC)
#APP_SOURCES	 = $(APP_SRC)/$(wildcard **/*.cpp)
#APP_OBJS	 = $(APP_BIN)
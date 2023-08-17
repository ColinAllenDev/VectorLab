## Compiler Configuration 
CPPC 				= g++
STANDARD_FLAGS		= -std=c++14
WARNING_FLAGS		= -Wall
DEBUG_FLAGS		 	= -g3
OPT_FLAGS			= -O0
COMPILE_ONLY_FLAG	= -c

CPP_FLAGS = $(STANDARD_FLAGS) $(DEBUG_FLAGS) $(OPT_FLAGS) $(WARNING_FLAGS)

## VectorLab - Static Library 
VL_FNAME = libVectorLab.a
VL_SRC_PATH = VectorLab/src
VL_OBJ_PATH = VectorLab/build
VL_BIN_PATH = VectorLab/bin
VL_VENDOR_PATH = VectorLab/vendor

VL_INCLUDES = -I$(VL_VENDOR_PATH)/spdlog/include -I$(VL_VENDOR_PATH)/bgfx/include \
			  -I$(VL_VENDOR_PATH)/bx/include -I$(VL_VENDOR_PATH)/bimg/include
# TODO: Add platform-specific libraries 
# TODO: Find a way to automate building of submodules
VL_LIB_FLAGS	= -L$(VL_VENDOR_PATH)/bgfx/.build/linux64_gcc/bin/
VL_LIBS 		= -lbgfx-shared-libRelease -lfmt -lSDL2 -lGL -lX11 -ldl -lpthread -lrt  

VL_SRCS = $(wildcard $(VL_SRC_PATH)/**/*.cpp)
VL_OBJS = $(patsubst $(wildcard $(VL_SRC_PATH)/**/)%.cpp, VectorLab/build/%.o, $(VL_SRCS))

VectorLab/bin/$(VL_FNAME): $(VL_OBJS)
	ar rcs $@ $(VL_OBJS)
#	g++ $(VL_INCLUDES) $(VL_LIB_FLAGS) $(VL_CPP_FLAGS) $^ -o $@ $(VL_LIBS)

VectorLab/build/%.o: $(wildcard $(VL_SRC_PATH)/**/)%.cpp
	g++ $(VL_INCLUDES) $(CPP_FLAGS) $(COMPILE_ONLY_FLAG) $< -o $@

# Final Target
VectorLab: VectorLab/bin/$(VL_FNAME)

## Sandbox - Application
SB_FNAME = Sandbox

SB_SRC_PATH = Sandbox/src

SB_INCLUDES  = -IVectorLab/src/ -IVectorLab/src/Core
SB_LIB_FLAGS = -LVectorLab/bin/ -L$(VL_VENDOR_PATH)/bgfx/.build/linux64_gcc/bin/ 
SB_LIBS		 = -lVectorLab -lfmt -lSDL2 -lbgfxRelease -lbimgRelease -lbxRelease

SB_SRCS  = $(wildcard $(SB_SRC_PATH)**/*.cpp)
SB_OBJS  = $(patsubst $(wildcard $(SB_SRC_PATH)**/)%.cpp, Sandbox/build/%.o, $(SB_SRCS))

Sandbox/bin/$(SB_FNAME): $(SB_OBJS)
	g++ $(SB_INCLUDES) $(SB_LIB_FLAGS) $(CPP_FLAGS) $^ -o $@ $(SB_LIBS) 

Sandbox/build/%.o: $(wildcard $(SB_SRC_PATH)**/)%.cpp
	g++ $(SB_INCLUDES) $(CPP_FLAGS) $(COMPILE_ONLY_FLAG) $< -o $@

# Final Target
Sandbox: Sandbox/bin/$(SB_FNAME)

## Phony Targets
clean:
	@rm -rf VectorLab/bin/* VectorLab/build/*
	@rm -rf Sandbox/bin/* Sanbox/build/
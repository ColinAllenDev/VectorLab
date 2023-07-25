# CPP_OBJS - the files to compile
CPP_OBJS = src/Core/Core.cpp src/Window/Window.cpp src/main.cpp

# CC - defines the compiler type
CC = g++

# INCLUDE_DIRS - include directories
INCLUDE_DIRS = -Isrc/

# COMPILER_FLAGS - additional compilation options
# -w : suppress all warnings
COMPILER_FLAGS = -w

# LINKER_FLAGS - the libraries we're linking against
LINKER_FLAGS = -lSDL2 

# OUTPUT_DIR - the executable directory
OUTPUT_DIR := bin/
# OUTPUT_NAME - the name of out executable
OUTPUT_NAME := VL
# OUTPUT_PATH - concatinated output dir and name
#OUTPUT_PATH := $(OUTPUT_DIR)$(OUTPUT_NAME) 

# Targets
all : $(CPP_OBJS)
			$(CC) $(CPP_OBJS) $(INCLUDE_DIRS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_DIR)$(OUTPUT_NAME)
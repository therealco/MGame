#!/bin/bash

# Set the paths to your V8 include and library directories
V8_INCLUDE_DIR=/path/to/v8/include
V8_LIB_DIR=/path/to/v8/lib

# Compile the C++ code
g++ -std=c++17 -I$V8_INCLUDE_DIR -L$V8_LIB_DIR -lv8 -lv8_libplatform -o game_engine main.cpp

# Run the compiled game engine
./game_engine

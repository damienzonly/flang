cmake_minimum_required(VERSION 3.24)
project(flang)

set(CMAKE_CXX_STANDARD 20)
add_executable(flang src/main.cpp
        src/Tokenizer.cpp
        src/Tokenizer.h
        src/Parser.h
        src/Parser.cpp
        src/shared.cpp
        src/shared.h
        src/Generator.h src/Generator.cpp)
include_directories(libs/spdlog)
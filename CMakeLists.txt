cmake_minimum_required(VERSION 3.26)
project(flang)

set(CMAKE_CXX_STANDARD 20)

add_executable(flang src/main.cpp
        src/Parser.cpp
        src/Parser.h
)

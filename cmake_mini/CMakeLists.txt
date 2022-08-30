cmake_minimum_required(VERSION 3.13) # CMake version check

project(mini_build) # Create project
set(CMAKE_CXX_STANDARD 14) # Enable c++14 standard

#include_directories(src)
FILE(GLOB SRC_CCS src/*.cc)
add_executable(mini_build ${SRC_CCS} miniexe.cc)

#add_library(lf_list STATIC lock_free_linkedlist.cc)
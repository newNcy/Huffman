
PROJECT(huffman)
#SET(CMAKE_C_COMPILER "/mingw64/bin/gcc.exe")
#SET(CMAKE_CXX_COMPILER "/mingw64/bin/g++.exe")
cmake_minimum_required(VERSION 3.6)
add_compile_options(-std=c++11 -g)
include_directories(include)
AUX_SOURCE_DIRECTORY( src DIR_SRCS)
ADD_EXECUTABLE(huffman ${DIR_SRCS})

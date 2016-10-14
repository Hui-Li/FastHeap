cmake_minimum_required(VERSION 2.8)
project(FastHeap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FastHeap.h)
add_executable(HeapTest ${SOURCE_FILES})
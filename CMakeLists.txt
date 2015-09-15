cmake_minimum_required(VERSION 3.3)
project(CQueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES queue.c queue.h)
add_executable(CQueue ${SOURCE_FILES})
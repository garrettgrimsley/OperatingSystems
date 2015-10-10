cmake_minimum_required(VERSION 3.3)
<<<<<<< HEAD
project(CQueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES queue.c queue.h)
add_executable(CQueue ${SOURCE_FILES})
=======
project(CPUScheduling)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpu.c cpu.h queue.h dialog.c)
add_executable(CPUScheduling ${SOURCE_FILES})
>>>>>>> Scheduler

cmake_minimum_required(VERSION 3.5)
project(factorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp big_arithmetic.cpp big_arithmetic.h progress.cpp progress.h elapsed_time.cpp elapsed_time.h)
add_executable(factorial ${SOURCE_FILES})
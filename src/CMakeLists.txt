cmake_minimum_required(VERSION 3.5)
project(big_arithmetic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(INCLUDE_DIRECTORIES ../include)
include_directories(../include)

file(GLOB SOURCE_LIB *.cpp)
add_library(big_arithmetic STATIC ${SOURCE_LIB})
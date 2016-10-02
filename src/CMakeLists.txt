cmake_minimum_required(VERSION 3.5)
project(big_arithmetic)

include_directories(../include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB SOURCE_LIB *.cpp)
add_library(big_arithmetic STATIC ${SOURCE_LIB})
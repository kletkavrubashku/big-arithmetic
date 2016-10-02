cmake_minimum_required(VERSION 3.5)
project(factorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

set(LIB_PATH ../..)
include_directories(${LIB_PATH}/include)

add_executable(factorial ${SOURCE_FILES})
target_link_libraries(factorial big_arithmetic)
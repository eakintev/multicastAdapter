cmake_minimum_required(VERSION 3.5)
project(multicastAdapter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lws2_32")

set(SOURCE_FILES main.cpp)
add_executable(multicastAdapter ${SOURCE_FILES})
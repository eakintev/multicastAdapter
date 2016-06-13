cmake_minimum_required(VERSION 3.5)
project(multicastAdapter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

find_package(Boost 1.61.0)
include_directories(${Boost_INCLUDE_DIRS})
# target_link_libraries(multicastAdapter Boost)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

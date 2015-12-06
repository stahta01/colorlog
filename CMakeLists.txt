cmake_minimum_required(VERSION 2.8)
project(colorlog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES colorlog.cc)
add_executable(colorlog ${SOURCE_FILES})

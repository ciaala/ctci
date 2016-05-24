cmake_minimum_required(VERSION 3.5)
project(ctci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/chapter5/main.cpp)
add_executable(ctci ${SOURCE_FILES})
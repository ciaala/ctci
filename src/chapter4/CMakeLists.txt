cmake_minimum_required(VERSION 3.5)
project(chapter4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        GraphNode.cpp
        GraphNode.h
        main.cpp)

include_directories(.)

add_executable(chapter4 ${SOURCE_FILES})
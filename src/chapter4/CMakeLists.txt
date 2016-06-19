#cmake_minimum_required(VERSION 3.5)
#project(chapter4)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#set(SOURCE_FILES
#        GraphNode.cpp
#        GraphNode.h
#        main.cpp)

#include_directories(.)

#add_executable(chapter4 ${SOURCE_FILES})


get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(SOURCE_FILES
        GraphNode.cpp
        GraphNode.h
        main.cpp)



add_library(${LIBRARY_NAME} ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
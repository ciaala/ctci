cmake_minimum_required(VERSION 3.5)
SET(CMAKE_BUILD_TYPE Debug)
project(ctci)

#SET(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -o0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -o0")
find_package(Threads)
set(SOURCE_FILES
        src/main.cpp
        )
add_subdirectory(src/chapter1)
add_subdirectory(src/chapter2)
add_subdirectory(src/chapter3)
add_subdirectory(src/chapter4)
add_subdirectory(src/chapter5)
add_subdirectory(src/chapter7)
add_subdirectory(src/chapter10)
add_subdirectory(src/chapter15)
add_subdirectory(src/chapter16)
add_subdirectory(src/chapter17)

add_executable(ctci ${SOURCE_FILES})

target_link_libraries(ctci LINK_PUBLIC debug
        chapter1
        chapter2
        chapter3
        chapter4
        chapter5
        chapter7
        chapter10
        chapter15
        chapter16
        chapter17
        ${CMAKE_THREAD_LIBS_INIT})
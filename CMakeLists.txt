cmake_minimum_required(VERSION 3.5)

project(ctci)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -o0")
find_package(Threads)
set(SOURCE_FILES
        src/main.cpp
        src/chapter3/main.cpp
        )
add_subdirectory(src/chapter1)
add_subdirectory(src/chapter4)
add_subdirectory(src/chapter5)
add_subdirectory(src/chapter7)
add_subdirectory(src/chapter10)
add_subdirectory(src/chapter15)
add_subdirectory(src/chapter16)
add_subdirectory(src/chapter17)

add_executable(ctci ${SOURCE_FILES})

target_link_libraries(ctci LINK_PUBLIC
        chapter1
        chapter4
        chapter5
        chapter7
        chapter10
        chapter15
        chapter16
        chapter17
        ${CMAKE_THREAD_LIBS_INIT})
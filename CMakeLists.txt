cmake_minimum_required(VERSION 3.5)
project(ctci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp

        src/chapter1/main.cpp
        src/chapter1/exercise1.cpp


        src/chapter5/exercise52.cpp
        src/chapter5/exercise53.cpp
        src/chapter5/exercise54.cpp
        src/chapter5/exercise55.cpp
        src/chapter5/exercise56.cpp
        src/chapter5/exercise57.cpp
        src/chapter5/main.cpp src/chapter5/exercise58.cpp)
add_executable(ctci ${SOURCE_FILES})
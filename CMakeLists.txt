cmake_minimum_required(VERSION 3.5)
project(ctci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        src/main.cpp

        src/chapter1/main.cpp
        src/chapter1/exercise1.cpp

        src/chapter3/main.cpp

        src/chapter4/main.cpp
        src/chapter4/GraphNode.cpp




        )
add_subdirectory(src/chapter5)
add_subdirectory(src/chapter7)
add_subdirectory(src/chapter10)
add_subdirectory(src/chapter15)
add_subdirectory(src/chapter16)
add_executable(ctci ${SOURCE_FILES})

target_link_libraries(ctci LINK_PUBLIC chapter7 chapter10 chapter15 chapter16)
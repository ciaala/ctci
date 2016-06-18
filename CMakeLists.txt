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

        src/chapter5/exercise52.cpp
        src/chapter5/exercise53.cpp
        src/chapter5/exercise54.cpp
        src/chapter5/exercise55.cpp
        src/chapter5/exercise56.cpp
        src/chapter5/exercise57.cpp
        src/chapter5/exercise58.cpp
        src/chapter5/main.cpp


        src/chapter7/exercise1/Deck.cpp
        src/chapter7/exercise1/Deck.h
        src/chapter7/exercise1/Blackjack.cpp
        src/chapter7/exercise1/Blackjack.h
        src/chapter7/exercise1/Card.cpp
        src/chapter7/exercise1/Card.h

        src/chapter7/exercise2/Employee.cpp
        src/chapter7/exercise2/Employee.h
        src/chapter7/exercise2/CallHandler.cpp
        src/chapter7/exercise2/CallHandler.h
        src/chapter7/exercise2/CallRank.cpp
        src/chapter7/exercise2/CallRank.h
        src/chapter7/exercise2/Caller.cpp
        src/chapter7/exercise2/Caller.h
        src/chapter7/exercise2/main.cpp

        )
add_subdirectory(src/chapter7)
add_subdirectory(src/chapter10)
add_subdirectory(src/chapter16)
add_executable(ctci ${SOURCE_FILES})

target_link_libraries(ctci LINK_PUBLIC chapter7 chapter10)
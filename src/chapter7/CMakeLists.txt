set(SOURCE_FILES

        exercise1/Deck.cpp
        exercise1/Deck.h
        exercise1/Blackjack.cpp
        exercise1/Blackjack.h
        exercise1/Card.cpp
        exercise1/Card.h

        exercise2/Employee.cpp
        exercise2/Employee.h
        exercise2/CallHandler.cpp
        exercise2/CallHandler.h
        exercise2/CallRank.cpp
        exercise2/CallRank.h
        exercise2/Caller.cpp
        exercise2/Caller.h
        exercise2/main.cpp

        exercise11/Filesystem.cpp
        exercise11/Filesystem.h)

add_library(chapter7 ${SOURCE_FILES})

target_include_directories(chapter7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
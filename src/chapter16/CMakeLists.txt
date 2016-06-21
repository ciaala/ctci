set(SOURCE_FILES
        main.cpp
        exercise3/main.cpp
        exercise4/main.cpp
        exercise5/main.cpp
        exercise6/main.cpp
        exercise7/main.cpp
        exercise8/main.cpp
        exercise9/main.cpp
        exercise10/main.cpp
        exercise11/main.cpp
        exercise12/main.cpp
        exercise13/main.cpp
        exercise14/main.cpp
        exercise15/main.cpp

        )

add_library(chapter16 ${SOURCE_FILES})

target_include_directories(chapter16 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


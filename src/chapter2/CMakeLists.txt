SET(CMAKE_BUILD_TYPE Debug)

SET( SOURCE_FILES
        main.cpp
        exercise1/main.cpp
        exercise2/main.cpp
        exercise3/main.cpp
        exercise4/main.cpp
        exercise5/main.cpp
        exercise6/main.cpp
        exercise7/main.cpp
        exercise8/main.cpp
        exercise9/main.cpp
        library/ListDecorator.h)
add_library(chapter2 ${SOURCE_FILES})
target_include_directories(chapter2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
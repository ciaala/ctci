SET( SOURCE_FILES
        main.cpp
        exercise1/main.cpp
        exercise2/main.cpp
        exercise3/main.cpp
        exercise4/main.cpp
        exercise11/main.cpp)
add_library(chapter1 ${SOURCE_FILES})
target_include_directories(chapter1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
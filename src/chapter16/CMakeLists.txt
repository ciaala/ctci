set(SOURCE_FILES
        main.cpp
        exercise3/main.cpp
        exercise4/main.cpp)

add_library(chapter16 ${SOURCE_FILES})

target_include_directories(chapter16 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


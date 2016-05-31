set(SOURCE_FILES
        exercise11/FileSystem.cpp
        exercise11/FileSystem.h)

add_library(chapter7 ${SOURCE_FILES})

target_include_directories(chapter7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
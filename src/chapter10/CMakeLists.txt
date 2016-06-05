set(SOURCE_FILES
        exercise1/SortedMerge.cpp
        exercise1/SortedMerge.h

        main.cpp)

add_library(chapter10 ${SOURCE_FILES})

target_include_directories(chapter10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
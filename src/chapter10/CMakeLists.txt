set(SOURCE_FILES
        main.cpp
        exercise1/SortedMerge.cpp
        exercise1/SortedMerge.h

        exercise4/Listy.cpp
        exercise4/Listy.h
        exercise4/SortedSearchNoSize.cpp exercise4/SortedSearchNoSize.h)

add_library(chapter10 ${SOURCE_FILES})

target_include_directories(chapter10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES

        exercise52.cpp
        exercise53.cpp
        exercise54.cpp
        exercise55.cpp
        exercise56.cpp
        exercise57.cpp
        exercise58.cpp
        main.cpp
        )

add_library(chapter5 ${SOURCE_FILES})

target_include_directories(chapter5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
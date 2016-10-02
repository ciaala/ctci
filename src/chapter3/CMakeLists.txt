get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)


set(SOURCE_FILES
        main.cpp
        exercise_03_1/main_03_1.cpp
        exercise_03_2/main_03_2.cpp
        exercise_03_3/main_03_3.cpp
        exercise_03_4/main_03_4.cpp
        exercise_03_5/main_03_5.cpp
        exercise_03_6/main_03_6.cpp
        )


add_library(${LIBRARY_NAME} ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
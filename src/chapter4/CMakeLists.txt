SET(CMAKE_BUILD_TYPE Debug)
get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


set(SOURCE_FILES
        exercise_04_1/main_04_1.cpp
        #    exercise_04_2/main_04_2.cpp
        library/TreeNode.h
        library/GraphNode.h
        library/AVLTree.h
        #
        main.cpp
        )


add_library(${LIBRARY_NAME} ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)


set(SOURCE_FILES
        main.cpp
        exercise1/main.cpp

        #        exercise2/main.cpp
        #        exercise3/main.cpp
        #        exercise4/main.cpp
                exercise5/main.cpp
        #        exercise6/main.cpp
        #        exercise7/main.cpp
        #        exercise8/main.cpp
        #        exercise9/main.cpp
        #
        #        exercise10/main.cpp
        #        exercise11/main.cpp
        #        exercise12/main.cpp
        #        exercise13/main.cpp
        #        exercise14/main.cpp
        #        exercise15/main.cpp
        #        exercise16/main.cpp
        #        exercise17/main.cpp
        #        exercise18/main.cpp
        #        exercise19/main.cpp
        #
        #        exercise20/main.cpp
        #        exercise21/main.cpp
        #        exercise22/main.cpp
        #        exercise23/main.cpp
        #        exercise24/main.cpp
        #        exercise25/main.cpp
        #        exercise26/main.cpp

        )


add_library(${LIBRARY_NAME} ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
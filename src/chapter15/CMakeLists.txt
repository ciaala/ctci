get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(SOURCE_FILES
        main.cpp

        exercise3/Philosopher.cpp
        exercise3/Philosopher.h
        exercise3/Table.cpp
        exercise3/Table.h
        exercise3/Chopstick.cpp
        exercise3/Chopstick.h
        exercise3/main.cpp
        exercise3/Seat.cpp
        exercise3/Seat.h

        exercise5/main.cpp
        exercise7/main.cpp)


add_library(${LIBRARY_NAME} ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.5)

project (ftop)

set (ftop_VERSION_MAJOR 1)
set (ftop_VERSION_MINOR 0)
set (ftop_VERSION "${ftop_VERSION_MAJOR}.${ftop_VERSION_MINOR}")

set (CMAKE_BUILD_TYPE Release)

set (CMAKE_C_STANDARD 23)
set (CMAKE_C_STANDARD_REQUIRED True)

set (CMAKE_C_FLAGS "${CMAKE_CFLAGS} -O2 -Wall")

include_directories ("${PROJECT_SOURCE_DIR}/include")

file(GLOB
        CS "../src/*.c"
    )
    add_executable(${PROJECT_NAME} ${CS})

cmake_minimum_required(VERSION 3.27)
project(ARingQ)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(LINK_DIR ./lib)
link_directories(${LINK_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(ARingQ
        src/main.cpp
        include/utils.h
        src/utils.cpp
        include/Parameter.h
        src/Parameter.cpp
        include/Confusion.h
        src/Confusion.cpp
        src/Cryptography.cpp
        include/Cryptography.h
        src/File.cpp
        include/File.h
        src/Core.cpp
        include/Core.h
        src/LoadLibrary.cpp
        include/LoadLibrary.h
)


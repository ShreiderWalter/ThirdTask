cmake_minimum_required (VERSION 2.6)

project (ThirdTask)

set_property(GLOBAL PROPERTY ON)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

if(UNIX)
    set (HEADERS 
    "LinuxSystemResourceHelper.h"
    "SystemResourceHelper.h"
    )

    set (SOURCES
    "LinuxSystemResourceHelper.cpp"
    "main.cpp"
    )
else()
    set (HEADERS 
    "WindowsSystemResourceHelper.h"
    "SystemResourceHelper.h"
    )

    set (SOURCES
    "WindowsSystemResourceHelper.cpp"
    "main.cpp"
    )
endif()

source_group("Header files" FILES ${HEADERS})

source_group("Source files" FILES ${SOURCES})

set (PROJECT_CONTENT ${SOURCES} ${HEADERS})

add_executable (SystemMonitor ${PROJECT_CONTENT})

set_property(TARGET SystemMonitor PROPERTY FOLDER "executables")

install (TARGETS SystemMonitor RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)


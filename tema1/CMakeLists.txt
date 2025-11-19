# Minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Project name
project(tema1)

if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()    

include_directories(${PROJECT_SOURCE_DIR}/src)

# Source files
set(SOURCES
    src/main.cpp
    src/vector.hpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build
)
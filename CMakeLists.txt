# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


cmake_minimum_required(VERSION 3.25)
project(cpp_syntax LANGUAGES C CXX)

# 设置C++标准版本为C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED OUTPUT_NAME)

message(STATUS "start running cmake...")

# 载入boost库
find_package(Boost 1.86.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    add_definitions(-D_GNU_SOURCE)
endif()

set(DIR_COMPILE $ENV{DIR_COMPILE})

set(SUB_DIR_LIST 
    00-some-tools
    01-basic
    02-class
    03-smart-point
    07-multithreading
)

if(DIR_COMPILE)
    add_subdirectory(${DIR_COMPILE})
else()
    foreach(subdir ${SUB_DIR_LIST})
        add_subdirectory(${subdir})
    endforeach()
endif()
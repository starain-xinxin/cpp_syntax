# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


cmake_minimum_required(VERSION 3.25)
project(cpp_syntax LANGUAGES C CXX)

# 设置C++标准版本为C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

ADD_SUBDIRECTORY(00-some-tools)
ADD_SUBDIRECTORY(02-class)
ADD_SUBDIRECTORY(01-basic)
ADD_SUBDIRECTORY(03-smart-point)
ADD_SUBDIRECTORY(07-multithreading)
# minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.26)

# name of the project
project(csi281)

# cpp package manager
include(cmake/get_cpm.cmake)

# check compiler and set the highest c++ standard available
include(cmake/compiler_check.cmake)

# static analyser to predict code smells
#include(cmake/static_analyser.cmake)

# add the testing package
CPMAddPackage("gh:onqtam/doctest#v2.4.11")
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
include_directories(${doctest_SOURCE_DIR})

# pretty format
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")

# enable testing
enable_testing()

# add lib
add_subdirectory(lib)
include_directories(lib)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

# memory leak tracker
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MLD)
set(MLD_H ${CMAKE_CURRENT_SOURCE_DIR}/MLD/MemoryLeakDetector.h)
set(MLD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/MLD/MemoryLeakDetector.cpp)

# the assignment subdirectory will hold all of the assignments

# todo for tolsta: make this simpler
# todo for the students: enable / disable assignments at your will
add_subdirectory(assignment01)
add_subdirectory(assignment02)
add_subdirectory(assignment03)
add_subdirectory(assignment04)
add_subdirectory(assignment05)
add_subdirectory(assignment06)
add_subdirectory(assignment07)
add_subdirectory(assignment08)
add_subdirectory(assignment09)
add_subdirectory(assignment10)
add_subdirectory(assignment11)
add_subdirectory(assignment12)

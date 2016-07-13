###############################################################################
# CMake build script for Data Structure and Algorithm.
#
# This project use Google Test as unit test framework, Our use Google C++ Style
# Guide in this project, in order to checking source files automatic, a custom
# target be created to call the lint tool "cpplint.py".

cmake_minimum_required(VERSION 2.6.2)

project(data_structure_and_algorithm CXX C)

# Define helper functions and macros used by Data Structure and Algorithm.
include(cmake/internal_utils.cmake)
fix_default_compiler_settings()  # Defined in internal_utils.cmake.

# Add Google Test as a subproject of our project.
add_subdirectory(gtest)
include_directories(gtest/include)

# Our project header files location.
include_directories(include)

# In our project, we organize all source files of each target through cmake
# script files recursive including. Every folder with source files in it,
# should have a cmake script file "source.cmake", and each cmake script file
# include this file(CMakeLists.txt) should contain its all sub folder's
# "source.cmake" by "include" command.
include(src/source.cmake)
include(test/source.cmake)

# Because variable "UNIT_TEST_SOURCES" is defined in above cmake script files,
# so we must lay all "add_executable" commands bellow to any "include" command
# which aim to include "source.cmake". 
add_executable(data_structure_and_algorithm_test ${UNIT_TEST_SOURCES})
target_link_libraries(data_structure_and_algorithm_test gtest_main)


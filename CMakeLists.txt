# Copyright (c) 2016 Johnson9009. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files(the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions :
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
# OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# CMake build script for Data Structure and Algorithm.
#
# This project use Google Test as unit test framework, Our use Google C++ Style Guide in this
# project, in order to checking source files automatic, a custom target be created to call the lint
# tool "cpplint.py".

cmake_minimum_required(VERSION 2.6.2)
project(data_structure_algorithm CXX C)

# Define helper functions and macros used by Data Structure and Algorithm.
include(utils/internal_utils.cmake)
fix_default_compiler_settings()  # Defined in internal_utils.cmake.

# Add Google Test as a subproject of our project.
add_subdirectory(gtest)
include_directories(gtest/include)

# Our project header files location.
include_directories(include)

# In our project, we organize all source files of each target through CMake script files recursive
# including. Every directory with source files in it, must have a CMake script file "source.cmake",
# and each CMake script file(this file(CMakeLists.txt) no exception) should contain all its sub
# directory's "source.cmake" by "include" command.
include(${CMAKE_CURRENT_LIST_DIR}/src/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/test/source.cmake)

# Because source file list of each target, such as "UNIT_TEST_SOURCES", is defined in above CMake
# script files, so we must lay all commands which need source file list, such as "add_executable",
# bellow to any "include" command which aim to include "source.cmake".
add_executable(cxx_data_structure_test ${CXX_DATA_STRUCTURE_TEST_SRCS})
target_link_libraries(cxx_data_structure_test gtest_main)
add_style_check(cxx_data_structure_test
  EXCLUDE_DIRS gtest
)

add_executable(c_data_structure_test ${C_DATA_STRUCTURE_TEST_SRCS})
target_link_libraries(c_data_structure_test gtest_main)
add_style_check(c_data_structure_test
  EXCLUDE_DIRS gtest
)

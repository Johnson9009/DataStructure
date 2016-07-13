###############################################################################
# Define functions and macros useful for building Data Structure and Algorithm.
#
# Tweaks CMake's default compiler/linker settings to suit needs of Data
# Structure and Algorithm. This macro is modified from Google Test. 
#
# This must be a macro(), as inside a function string() can only
# update variables in the function scope.
macro(fix_default_compiler_settings)
  if (MSVC)
    # For MSVC, CMake sets certain flags to defaults we want to override.
    # This replacement code is taken from sample in the CMake Wiki at
    # http://www.cmake.org/Wiki/CMake_FAQ#Dynamic_Replace.
    foreach (flag_var
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      # Data Structure and Algorithm is preferable to use CRT as static
      # libraries, as we don't have to rely on CRT DLLs being available. CMake
      # always defaults to using shared CRT libraries, so we override that
      # default here.
      string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")

      # We prefer more strict warning checking for building Data Structure and
      # Algorithm. Replaces /W3 with /W4 in defaults.
      string(REPLACE "/W3" "-W4" ${flag_var} "${${flag_var}}")
    endforeach()
  endif()
endmacro()

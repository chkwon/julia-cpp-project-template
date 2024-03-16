cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(C_JULIA VERSION 1.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add the executable
add_executable(runbar cpp_code/bar.cpp)

add_library(lib SHARED cpp_code/bar.cpp cpp_code/c_interface.cpp)
set_target_properties(lib PROPERTIES OUTPUT_NAME bar)


include(CTest)

# Test Library
add_subdirectory(cpp_code/ctest/)
add_test(NAME       lib_test_c
         COMMAND    lib_test_c)
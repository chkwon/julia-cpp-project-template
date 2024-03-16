cmake_minimum_required(VERSION 3.15)
project(HGS_Test_c)
set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/cpp_code)

add_executable(lib_test_c
        test.c
        ${CMAKE_SOURCE_DIR}/cpp_code/c_interface.h
        )

target_link_libraries(lib_test_c -lm lib)  # need -lm to link math library


        
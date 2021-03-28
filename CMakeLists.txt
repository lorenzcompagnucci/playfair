# cmake_minimum_required(VERSION <specify CMake version here>)
project(playfair C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c key.c key.h file.c file.h directory.c directory.h coding.c coding.h keygen.c keygen.h mem_utils.h mem_utils.c)
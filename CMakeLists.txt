# cmake_minimum_required(VERSION <specify CMake version here>)
project(playfair C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c elabutils.c elabutils.h key.c key.h file.c file.h directory.c directory.h encoding.c encoding.h decoding.c decoding.h keygen.c keygen.h)
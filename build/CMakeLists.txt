# cmake_minimum_required(VERSION <specify CMake version here>)
project(playfair C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c key/key.c key/key.h file/file.c file/file.h file/directory.c file/directory.h key/keygen.c key/keygen.h memory/mem_utils.h memory/mem_utils.c coding/playfair.h coding/playfair.c)
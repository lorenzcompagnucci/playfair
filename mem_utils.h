#ifndef PLAYFAIR_MEM_UTILS_H
#define PLAYFAIR_MEM_UTILS_H

#define MATRIX_ERR "ERROR WHILE ALLOCATING MEMORY FOR A MATRIX"
#define MATRIX_ROW_ERR "ERROR WHILE ALLOCATING MEMORY FOR A ROW"

#include "key.h"

char** create_matrix(int rows, int columns);
void free_string(char* string);
void check_string(char* string, char* errmessage);
void free_matrix(char** matrix, int rows);
void check_matrix(char** matrix, char* errmessage);
void free_key(key* k);
void free_key_data(key_data* kd);

#endif //PLAYFAIR_MEM_UTILS_H
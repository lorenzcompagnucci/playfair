#ifndef PLAYFAIR_MEM_UTILS_H
#define PLAYFAIR_MEM_UTILS_H

#include "key.h"

void free_string(char* string);
void check_string(char* string, char* errmessage);
void free_matrix(char** matrix, int rows);
void check_matrix(char** matrix, char* errmessage);
void free_key(key* k);
void free_key_data(key_data* kd);

#endif //PLAYFAIR_MEM_UTILS_H
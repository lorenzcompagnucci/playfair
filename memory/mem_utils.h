#ifndef PLAYFAIR_MEM_UTILS_H
#define PLAYFAIR_MEM_UTILS_H

#define MATRIX_ERR "ERROR WHILE ALLOCATING MEMORY FOR A MATRIX"
#define MATRIX_ROW_ERR "ERROR WHILE ALLOCATING MEMORY FOR A ROW"

#include "../key/key.h"

char* Memory_createString(int length, char* error);
void Memory_freeString(char* string);
void Memory_checkString(char* string, char* errmessage);
char** Memory_allocateMatrix(int rows, int columns);
void Memory_deallocateMatrix(char** matrix, int rows);
void Memory_checkMatrix(char** matrix, char* errmessage);
void Memory_freeKey(Key_key_t* k);
void Memory_freeKeyData(Key_Key_Data_t* kd);

#endif //PLAYFAIR_MEM_UTILS_H
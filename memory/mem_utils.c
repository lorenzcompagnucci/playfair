#include <stdio.h>
#include <stdlib.h>

#include "mem_utils.h"

char* Memory_createString(int length, char* error) {
    char* buffer = (char*) malloc(sizeof(char) * length);
    Memory_checkString(buffer, error);
    return buffer;
}

void Memory_freeString(char* string) {
    if (string != NULL) {
        free(string);
        string = NULL;
    }
}

void Memory_checkString(char* string, char* errmessage) {
    if (string == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char** Memory_allocateMatrix(int rows, int columns) {
    char** matrix = (char**) malloc(sizeof(char*) * rows);
    Memory_checkMatrix(matrix, MATRIX_ERR);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*) calloc(columns, sizeof(char));
        Memory_checkString(matrix[i], MATRIX_ROW_ERR);
    }
    return matrix;
}

void Memory_deallocateMatrix(char** matrix, int rows) {
    if (matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            Memory_freeString(matrix[i]);
        }
        free(matrix);
        matrix = NULL;
    }
}

void Memory_checkMatrix(char** matrix, char* errmessage) {
    if (matrix == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void Memory_freeKey(Key_key_t* k) {
    Memory_freeKeyData(k->kd);
    Memory_deallocateMatrix(k->matrix, 5);
    free(k);
    k = NULL;
}

void Memory_freeKeyData(Key_Key_Data_t* kd) {
    Memory_freeString(kd->alphabet);
    Memory_freeString(kd->replacement);
    Memory_freeString(kd->special);
    Memory_freeString(kd->keyword);
    free(kd);
    kd = NULL;
}
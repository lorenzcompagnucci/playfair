#include <stdio.h>
#include <stdlib.h>

#include "mem_utils.h"

char* create_string(int length, char* error) {
    char* buffer = (char*) malloc(sizeof(char) * length);
    check_string(buffer, error);
    return buffer;
}

void free_string(char* string) {
    if (string != NULL) {
        free(string);
        string = NULL;
    }
}

void check_string(char* string, char* errmessage) {
    if (string == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char** create_matrix(int rows, int columns) {
    char** matrix = (char**) malloc(sizeof(char*) * rows);
    check_matrix(matrix, MATRIX_ERR);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*) calloc(columns, sizeof(char));
        check_string(matrix[i], MATRIX_ROW_ERR);
    }
    return matrix;
}

void free_matrix(char** matrix, int rows) {
    if (matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            free_string(matrix[i]);
        }
        free(matrix);
        matrix = NULL;
    }
}

void check_matrix(char** matrix, char* errmessage) {
    if (matrix == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void free_key(key* k) {
    free_key_data(k->kd);
    free_matrix(k->matrix, 5);
    free(k);
    k = NULL;
}

void free_key_data(key_data* kd) {
    free_string(kd->alphabet);
    free_string(kd->replacement);
    free_string(kd->special);
    free_string(kd->keyword);
    free(kd);
    kd = NULL;
}
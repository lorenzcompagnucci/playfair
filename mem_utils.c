#include <stdio.h>
#include <stdlib.h>

#include "mem_utils.h"

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

void free_matrix(char** matrix) {
    if (matrix != NULL) {
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
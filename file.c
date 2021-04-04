#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"
#include "mem_utils.h"

char* read_file(char* input_file) {
    FILE* fin = fopen(input_file, "r");
    check_file(fin, FIN_ERROR);
    char* buffer = reader(fin);
    fclose(fin);
    return buffer;
}

char* reader(FILE* fin) {
    char* buffer = (char*) malloc(sizeof(char) * (file_size(fin)+1));
    check_string(buffer, INP_BUFF_ERROR);
    int i = 0;
    char c;
    while ((c = toupper(fgetc(fin))) != EOF) {
        if ((c >= 'A' && c <= 'Z') || c == '\r' || c == '\n') {
            buffer[i] = c;
            i++;
        }
    }
    buffer[i] = '\0';
    return buffer;
}

long int file_size(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

void check_file(FILE* fp, char* errmessage) {
    if (fp == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}
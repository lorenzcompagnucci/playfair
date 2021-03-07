#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.h"

char* read_file(char* inputFile) {
    FILE* fin = fopen(inputFile, "r");
    check_file(fin, INP_FILE);
    char* buffer = (char*) malloc(sizeof(char) * (file_size(fin)+1));
    reader(fin, buffer);
    fclose(fin);
    return buffer;
}

long int file_size(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

void reader(FILE* fin, char* buffer) {
    check_malloc(buffer, INP_BUFF);
    int i = 0;
    char c;
    while ((c = fgetc(fin)) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '\r' || c == '\n') {
            buffer[i] = toupper(c);
            i++;
        }
    }
    buffer[i] = '\0';
}

void check_file(FILE* fp, char* errmessage) {
    if (fp == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void check_malloc(char* buffer, char* errmessage) {
    if (buffer == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"
#include "../memory/mem_utils.h"

static long int fileSize(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

static char* reader(FILE* fin) {
    char* buffer = Memory_createString(fileSize(fin)+1, INP_BUFF_ERROR);
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

void File_checkFile(FILE* fp, char* errmessage) {
    if (fp == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char* File_readFile(char* input_file) {
    FILE* fin = fopen(input_file, "r");
    File_checkFile(fin, FIN_ERROR);
    char* buffer = reader(fin);
    fclose(fin);
    return buffer;
}
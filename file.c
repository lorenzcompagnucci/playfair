#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.h"

char* readFile(char* inputFile) {
    FILE* fin = fopen(inputFile, "r");
    if (fin == NULL) {
        perror("INPUT FILE ERROR");
        exit(0);
    }
    char* buffer = (char*) malloc(sizeof(char) * (fileSize(fin)+1));
    reader(fin, buffer);
    fclose(fin);
    return buffer;
}

long int fileSize(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

void reader(FILE* fin, char* buffer) {
    if (buffer == NULL) {
        perror("BUFFER ERROR");
        exit(0);
    }
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
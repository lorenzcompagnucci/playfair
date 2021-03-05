#ifndef PLAYFAIR_FILE_H
#define PLAYFAIR_FILE_H

#include <stdio.h>

void reader(FILE* fin, char* buffer);
long int fileSize(FILE* fp);
char* readFile(char* inputFile);

#endif //PLAYFAIR_FILE_H
#ifndef PLAYFAIR_FILE_H
#define PLAYFAIR_FILE_H

#include <stdio.h>

#define INP_FILE "INPUT FILE ERROR"
#define INP_BUFF "INPUT FILE BUFFER ERROR"

void reader(FILE* fin, char* buffer);
long int file_size(FILE* fp);
char* read_file(char* inputFile);
void check_file(FILE* fp, char* errmessage);

#endif //PLAYFAIR_FILE_H
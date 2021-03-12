#ifndef PLAYFAIR_FILE_H
#define PLAYFAIR_FILE_H

#include <stdio.h>

#define INP_FILE_ERROR "INPUT FILE ERROR"
#define INP_BUFF_ERROR "INPUT FILE BUFFER ERROR"

char* read_file(char* inputFile);
char* reader(FILE* fin);
long int file_size(FILE* fp);
void check_file(FILE* fp, char* errmessage);

#endif //PLAYFAIR_FILE_H
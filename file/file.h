#ifndef PLAYFAIR_FILE_H
#define PLAYFAIR_FILE_H

#include <stdio.h>

#define FIN_ERROR "INPUT FILE ERROR"
#define FOUT_ERROR "ERROR WHILE OPENING A FILE"
#define INP_BUFF_ERROR "INPUT FILE BUFFER ERROR"

char* File_readFile(char* input_file);
void File_checkFile(FILE* fp);

#endif //PLAYFAIR_FILE_H
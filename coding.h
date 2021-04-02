#ifndef PLAYFAIR_CODING_H
#define PLAYFAIR_CODING_H

#define CODED_FILE_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

#include "key.h"

void code_file(char* command, char* outputDir, char* inputFile, key* chiave);
void print_couples(key* chiave, char* message, char* command, FILE* fout);
char* create_couple(char* message, int i, int* p, key* chiave);
void encode_couple(key* chiave, char* couple);
void decode_couple(key* chiave, char* couple);
void find_positions(key* chiave, char l, int* riga, int* colonna);

#endif //PLAYFAIR_CODING_H
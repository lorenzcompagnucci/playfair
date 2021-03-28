#ifndef PLAYFAIR_CODING_H
#define PLAYFAIR_CODING_H

#define OUT_FILE_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

#include "key.h"

void code_file(key* chiave, char* outputDir, char* inputFile, char* command);
char** divide_couples(key* chiave, char* message, int rows);
void create_couple(char* message, key* chiave, int *i, char* couple);
void code_couple(key* chiave, char** couples, char* command);
void encode_couple(key* chiave, char* couple);
void decode_couple(key* chiave, char* couple);
void find_positions(key* chiave, char l, int* riga, int* colonna);

#endif //PLAYFAIR_CODING_H
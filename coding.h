#ifndef PLAYFAIR_CODING_H
#define PLAYFAIR_CODING_H

#include "key.h"

void code_file(key* chiave, char* outputDir, char* inputFile, char* command);
char** divide_couples(key* chiave, char* message, int rows);
void encode_couple(key* chiave, char* couple);
void decode_couple(key* chiave, char* couple);

#endif //PLAYFAIR_CODING_H
#ifndef PLAYFAIR_DECODING_H
#define PLAYFAIR_DECODING_H

#include "key.h"

void decode_file(key* chiave, char* outputDir, char* inputFile);
void decode_messagge(key* chiave, char* message, FILE* fout);
void decode_couple(key* chiave, char* l1, char* l2);

#endif //PLAYFAIR_DECODING_H
#ifndef PLAYFAIR_ENCODING_H
#define PLAYFAIR_ENCODING_H

#include "key.h"

void encode_file(key* chiave, char* outputDir, char* inputFile);
void encode_messagge(key* chiave, char* message, FILE* fout);
void encode_couple(key* chiave, char* l1, char* l2);

#endif //PLAYFAIR_ENCODING_H
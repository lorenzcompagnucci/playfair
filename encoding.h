#ifndef PLAYFAIR_ENCODING_H
#define PLAYFAIR_ENCODING_H

#include "key.h"

void encodeFile(key* chiave, char* outputDir, char* inputFile);
void encodeMessagge(key* chiave, char* message, FILE* fout);
void encodeCouple(key* chiave, char* l1, char* l2);

#endif //PLAYFAIR_ENCODING_H
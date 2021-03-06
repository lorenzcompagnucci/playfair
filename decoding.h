#ifndef PLAYFAIR_DECODING_H
#define PLAYFAIR_DECODING_H

#include "key.h"

void decodeFile(key* chiave, char* outputDir, char* inputFile);
void decodeMessagge(key* chiave, char* message, FILE* fout);
void decodeCouple(key* chiave, char* l1, char* l2);

#endif //PLAYFAIR_DECODING_H
#ifndef PLAYFAIR_DECODING_H
#define PLAYFAIR_DECODING_H

#include "key.h"

void decodeFile(Key chiave, char* outputDir, char* inputFile);
void decodeMessagge(Key chiave, char* message, FILE* fout);
void decodeCouple(Key chiave, char* l1, char* l2);

#endif //PLAYFAIR_DECODING_H
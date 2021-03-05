#ifndef PLAYFAIR_ENCODING_H
#define PLAYFAIR_ENCODING_H

#include "key.h"

void encodeFile(Key chiave, char* outputDir, char* inputFile);
void encodeMessagge(Key chiave, char* message, FILE* fout);
void encodeCouple(Key chiave, char* l1, char* l2);

#endif //PLAYFAIR_ENCODING_H
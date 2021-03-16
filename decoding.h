#ifndef PLAYFAIR_DECODING_H
#define PLAYFAIR_DECODING_H

#include "key.h"

void decode_file(key* chiave, char* outputDir, char* inputFile);
void decode_couple(key* chiave, char* couple);

#endif //PLAYFAIR_DECODING_H
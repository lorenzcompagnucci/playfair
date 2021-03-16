#ifndef PLAYFAIR_ENCODING_H
#define PLAYFAIR_ENCODING_H

#include "key.h"

void encode_file(key* chiave, char* outputDir, char* inputFile);
void encode_couple(key* chiave, char* couple);

#endif //PLAYFAIR_ENCODING_H
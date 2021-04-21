#ifndef PLAYFAIR_ENCODING_H
#define PLAYFAIR_ENCODING_H

#include "key.h"

void encode_message(key* key, char* message, FILE* fout);
void encode_couple(key* key, char* couple);

#endif //PLAYFAIR_ENCODING_H
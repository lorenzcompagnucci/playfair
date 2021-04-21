#ifndef PLAYFAIR_DECODING_H
#define PLAYFAIR_DECODING_H

#include "key.h"

void decode_message(key* key, char* message, FILE* fout);
void decode_couple(key* key, char* couple);

#endif //PLAYFAIR_DECODING_H
#ifndef PLAYFAIR_ELABUTILS_H
#define PLAYFAIR_ELABUTILS_H

#include "key.h"

void fixMissingChars(Key chiave, char* buffer);
void findPositions(Key chiave, char *l, int* riga, int* colonna);

#endif //PLAYFAIR_ELABUTILS_H
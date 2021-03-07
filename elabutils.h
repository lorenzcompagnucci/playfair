#ifndef PLAYFAIR_ELABUTILS_H
#define PLAYFAIR_ELABUTILS_H

#include "key.h"

#define OUT_FILE "ERROR WHILE OPENING THE OUTPUT FILE"

void fix_missing_chars(key* chiave, char* buffer);
void find_positions(key* chiave, char *l, int* riga, int* colonna);

#endif //PLAYFAIR_ELABUTILS_H
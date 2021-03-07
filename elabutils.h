#ifndef PLAYFAIR_ELABUTILS_H
#define PLAYFAIR_ELABUTILS_H

#include "key.h"

#define OUT_FILE "ERROR WHILE OPENING THE OUTPUT FILE"

void fix_missing_chars(key* chiave, char* buffer);
void create_couples(char* message, key* chiave, char* l1, char* l2, int *i);
void find_positions(key* chiave, char *l, int* riga, int* colonna);

#endif //PLAYFAIR_ELABUTILS_H
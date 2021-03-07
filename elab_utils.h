#ifndef PLAYFAIR_ELAB_UTILS_H
#define PLAYFAIR_ELAB_UTILS_H

#include "key.h"

#define OUT_FILE_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

void fix_missing_chars(key* chiave, char* buffer);
void create_couples(char* message, key* chiave, char* l1, char* l2, int *i);
void find_positions(key* chiave, char *l, int* riga, int* colonna);

#endif //PLAYFAIR_ELAB_UTILS_H
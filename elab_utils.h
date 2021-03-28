#ifndef PLAYFAIR_ELAB_UTILS_H
#define PLAYFAIR_ELAB_UTILS_H

#include "key.h"

#define OUT_FILE_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

void create_couple(char* message, key* chiave, int *i, char* couple);
void find_positions(key* chiave, char l, int* riga, int* colonna);

#endif //PLAYFAIR_ELAB_UTILS_H
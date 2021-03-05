#include <string.h>

#include "elabutils.h"

void fixMissingChars(Key chiave, char* buffer) {
    for (int i = 0; i < strlen(buffer); ++i) {
        if (buffer[i] == chiave.mancante) {
            buffer[i] = chiave.sostituto;
        }
    }
}

void findPositions(Key chiave, char *l, int* riga, int* colonna) {
    for (int i = 0; i < 5 && *riga == -1; ++i) {
        for (int j = 0; j < 5 && *riga == -1; ++j) {
            if (chiave.matrice[i][j] == *l) {
                *riga = i;
                *colonna = j;
            }
        }
    }
}
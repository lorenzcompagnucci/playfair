#include <string.h>

#include "elab_utils.h"

void create_couple(char* message, key* chiave, int *i, char* couple) {
    couple[0] = message[*i];
    couple[1] = message[*i+1];
    for (int j = 0; j < strlen(couple); ++j) {
        if (couple[j] == chiave->mancante) {
            couple[j] = chiave->sostituto;
        }
    }
    if (couple[0] != couple[1] && couple[1] != '\0') {
        *i += 1;
    } else {
        couple[1] = chiave->speciale;
    }
}

void find_positions(key* chiave, char l, int* riga, int* colonna) {
    for (int i = 0; i < 5 && *riga == -1; ++i) {
        for (int j = 0; j < 5 && *riga == -1; ++j) {
            if (chiave->matrice[i][j] == l) {
                *riga = i;
                *colonna = j;
            }
        }
    }
}
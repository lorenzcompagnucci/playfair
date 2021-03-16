#include "elab_utils.h"

char* create_couple(char* message, key* chiave, int *i) {
    char couple[3];
    couple[0] = message[*i];
    couple[1] = message[*i+1];
    if (couple[0] == chiave->mancante) {
        couple[0] = chiave->sostituto;
    }
    if (couple[1] == chiave->mancante) {
        couple[1] = chiave->sostituto;
    }
    if (couple[0] != couple[1] && couple[1] != '\0') {
        *i += 1;
    } else {
        couple[1] = chiave->speciale;
    }
    return couple;
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
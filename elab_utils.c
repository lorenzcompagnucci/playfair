#include "elab_utils.h"

void create_couple(char* message, key* chiave, char* l1, char* l2, int *i) {
    *l1 = message[*i];
    *l2 = message[*i+1];
    if (*l1 == chiave->mancante) {
        *l1 = chiave->speciale;
    }
    if (*l2 == chiave->mancante) {
        *l2 = chiave->speciale;
    }
    if (*l1 != *l2 && *l2 != '\0') {
        *i += 1;
    } else {
        *l2 = chiave->speciale;
    }
}

void find_positions(key* chiave, char *l, int* riga, int* colonna) {
    for (int i = 0; i < 5 && *riga == -1; ++i) {
        for (int j = 0; j < 5 && *riga == -1; ++j) {
            if (chiave->matrice[i][j] == *l) {
                *riga = i;
                *colonna = j;
            }
        }
    }
}
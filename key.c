#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "file.h"

key* getKey(char* keyPath) {
    key* k = malloc(sizeof(key));
    k->matrice = (char**) malloc(sizeof(char*) * 5);
    for (int i = 0; i < 5; i++) {
        k->matrice[i] = (char*) calloc(5, sizeof(char));
    }
    char* buffer = readFile(keyPath);
    k->kd = getKeyData(buffer);
    free(buffer);
    buffer = NULL;
    setMatrix(k);
    setChars(k);
    return k;
}

key_data *getKeyData(char* buffer) {
    key_data* kd = (key_data*) malloc(sizeof(key_data));
    char* token = strtok(buffer, "\r\n");
    kd->alfabeto = (char*) malloc(sizeof(char) * (strlen(token)+1));
    strcpy(kd->alfabeto, token);
    token = strtok(NULL, "\r\n");
    kd->sostituto = (char*) malloc(sizeof(char) * (strlen(token)+1));
    strcpy(kd->sostituto, token);
    token = strtok(NULL, "\r\n");
    kd->speciale = (char*) malloc(sizeof(char) * (strlen(token)+1));
    strcpy(kd->speciale, token);
    token = strtok(NULL, "\r\n");
    kd->chiave = (char*) malloc(sizeof(char) * (strlen(token)+1));
    strcpy(kd->chiave, token);
    return kd;
}

void setMatrix(key* key) {
    for (int i = 0; i < strlen(key->kd->chiave); i++) {
        loopOnMatrix(key, key->kd->chiave[i]);
    }
    for (int i = 0; i < strlen(key->kd->alfabeto); i++) {
        loopOnMatrix(key, key->kd->alfabeto[i]);
    }
}

void loopOnMatrix(key* chiave, char c) {
    int counter = 0;
    for (int m = 0; m < 5 && counter == 0; m++) {
        for (int n = 0; n < 5 && counter == 0; n++) {
            if (chiave->matrice[m][n] == c) {
                counter++;
            } else if (chiave->matrice[m][n] == 0 && counter == 0) {
                chiave->matrice[m][n] = c;
                counter++;
            }
        }
    }
}

void setChars(key* chiave) {
    chiave->sostituto = chiave->kd->sostituto[0];
    chiave->speciale = chiave->kd->speciale[0];
    for (char x = 'A'; x <= 'Z'; x++) {
        chiave->mancante = x;
        int counter = 0;
        for (int i = 0; i < 5 && counter == 0; i++) {
            for (int j = 0; j < 5 && counter == 0; j++) {
                if (x == chiave->matrice[i][j]) {
                    counter = 1;
                }
            }
        }
        if (counter == 0) {
            break;
        }
    }
}

void freeKey(key* key) {
    freeKeyData(key->kd);
    for (int i = 0; i < 5; i++) {
        free(key->matrice[i]);
        key->matrice[i] = NULL;
    }
    free(key->matrice);
    key->matrice = NULL;
    free(key);
    key = NULL;
}

void freeKeyData(key_data* kd) {
    free(kd->alfabeto);
    kd->alfabeto = NULL;
    free(kd->sostituto);
    kd->sostituto = NULL;
    free(kd->speciale);
    kd->speciale = NULL;
    free(kd->chiave);
    kd->chiave = NULL;
    free(kd);
    kd = NULL;
}
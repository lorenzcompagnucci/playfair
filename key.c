#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "file.h"

void setKey(Key* chiave, char* keyPath) {
    char* buffer = readFile(keyPath);
    char* token = strtok(buffer, "\r\n");
    char* alfabeto = token;
    token = strtok(NULL, "\r\n");
    char* sostituto = token;
    token = strtok(NULL, "\r\n");
    char* speciale = token;
    token = strtok(NULL, "\r\n");
    char* parolachiave = token;
    setMatrix(chiave, alfabeto, parolachiave);
    setChars(chiave, sostituto[0], speciale[0]);
    free(buffer);
    buffer = NULL;
}

void setMatrix(Key* chiave, char* alfabeto, char* parolachiave) {
    for (int i = 0; i < strlen(parolachiave); i++) {
        loopOnMatrix(chiave, parolachiave[i]);
    }
    for (int i = 0; i < strlen(alfabeto); i++) {
        loopOnMatrix(chiave, alfabeto[i]);
    }
}

void loopOnMatrix(Key* chiave, char c) {
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

void setChars(Key* chiave, char sostituto, char speciale) {
    chiave->sostituto = sostituto;
    chiave->speciale = speciale;
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
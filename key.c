#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "file.h"

void setKey(Key* chiave, char* keyPath) {
    char* buffer = readFile(keyPath);
    setMatrix(chiave, buffer);
    setChars(chiave, buffer);
    free(buffer);
    buffer = NULL;
}

void setMatrix(Key* chiave, char* buffer) {
    for (int i = 33; buffer[i] != '\r'; ++i) {
        loopOnMatrix(chiave, buffer[i]);
    }
    for (int i = 0; i < 25; ++i) {
        loopOnMatrix(chiave, buffer[i]);
    }
}

void loopOnMatrix(Key* chiave, char c) {
    int counter = 0;
    for (int m = 0; m < 5 && counter == 0; ++m) {
        for (int n = 0; n < 5 && counter == 0; ++n) {
            if (chiave->matrice[m][n] == c) {
                counter++;
            } else if (chiave->matrice[m][n] == 0 && counter == 0) {
                chiave->matrice[m][n] = c;
                counter++;
            }
        }
    }
}

void setChars(Key* chiave, char* buffer) {
    chiave->sostituto = buffer[27];
    chiave->speciale = buffer[30];
    for (char x = 'A'; x <= 'Z'; x++) {
        chiave->mancante = x;
        int counter = 0;
        for (int i = 0; i < 5 && counter == 0; ++i) {
            for (int j = 0; j < 5 && counter == 0; ++j) {
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
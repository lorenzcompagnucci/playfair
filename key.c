#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "file.h"

key* get_key(char* keyPath) {
    key* k = malloc(sizeof(key));
    k->matrice = (char**) malloc(sizeof(char*) * 5);
    for (int i = 0; i < 5; i++) {
        k->matrice[i] = (char*) calloc(5, sizeof(char));
    }
    char* buffer = read_file(keyPath);
    k->kd = get_key_data(buffer);
    free(buffer);
    buffer = NULL;
    set_matrix(k);
    set_chars(k);
    return k;
}

key_data* get_key_data(char* buffer) {
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

void set_matrix(key* k) {
    for (int i = 0; i < strlen(k->kd->chiave); i++) {
        loop_on_matrix(k, k->kd->chiave[i]);
    }
    for (int i = 0; i < strlen(k->kd->alfabeto); i++) {
        loop_on_matrix(k, k->kd->alfabeto[i]);
    }
}

void loop_on_matrix(key* k, char c) {
    int counter = 0;
    for (int m = 0; m < 5 && counter == 0; m++) {
        for (int n = 0; n < 5 && counter == 0; n++) {
            if (k->matrice[m][n] == c) {
                counter++;
            } else if (k->matrice[m][n] == 0 && counter == 0) {
                k->matrice[m][n] = c;
                counter++;
            }
        }
    }
}

void set_chars(key* k) {
    k->sostituto = k->kd->sostituto[0];
    k->speciale = k->kd->speciale[0];
    for (char x = 'A'; x <= 'Z'; x++) {
        k->mancante = x;
        int counter = 0;
        for (int i = 0; i < 5 && counter == 0; i++) {
            for (int j = 0; j < 5 && counter == 0; j++) {
                if (x == k->matrice[i][j]) {
                    counter = 1;
                }
            }
        }
        if (counter == 0) {
            break;
        }
    }
}

void free_key(key* k) {
    free_key_data(k->kd);
    for (int i = 0; i < 5; i++) {
        free(k->matrice[i]);
        k->matrice[i] = NULL;
    }
    free(k->matrice);
    k->matrice = NULL;
    free(k);
    k = NULL;
}

void free_key_data(key_data* kd) {
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
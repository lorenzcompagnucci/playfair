#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "mem_utils.h"
#include "file.h"

key* get_key(char* keyPath) {
    key* k = malloc(sizeof(key));
    k->matrice = create_matrix(5, 5);
    char* buffer = read_file(keyPath);
    k->kd = get_key_data(buffer);
    free_string(buffer);
    set_matrix(k);
    set_chars(k);
    return k;
}

key_data* get_key_data(char* buffer) {
    key_data* kd = (key_data*) malloc(sizeof(key_data));
    char* token = strtok(buffer, "\r\n");
    kd->alfabeto = (char*) malloc(sizeof(char) * (strlen(token)+1));
    check_string(kd->alfabeto, KEY_DATA_ERROR);
    strcpy(kd->alfabeto, token);
    token = strtok(NULL, "\r\n");
    kd->sostituto = (char*) malloc(sizeof(char) * (strlen(token)+1));
    check_string(kd->sostituto, KEY_DATA_ERROR);
    strcpy(kd->sostituto, token);
    token = strtok(NULL, "\r\n");
    kd->speciale = (char*) malloc(sizeof(char) * (strlen(token)+1));
    check_string(kd->speciale, KEY_DATA_ERROR);
    strcpy(kd->speciale, token);
    token = strtok(NULL, "\r\n");
    kd->chiave = (char*) malloc(sizeof(char) * (strlen(token)+1));
    check_string(kd->chiave, KEY_DATA_ERROR);
    strcpy(kd->chiave, token);
    return kd;
}

void set_matrix(key* k) {
    char* positions = (char*) calloc(2, sizeof(char));
    check_string(positions, POSITIONS_ERROR);
    for (int i = 0; i < strlen(k->kd->chiave); i++) {
        if (!(positions[0] == 4 && positions[1] == 4)) {
            loop_on_matrix(k, positions, k->kd->chiave[i]);
        }
    }
    for (int i = 0; i < strlen(k->kd->alfabeto); i++) {
        if (!(positions[0] == 4 && positions[1] == 4)) {
            loop_on_matrix(k, positions, k->kd->alfabeto[i]);
        }
    }
    free_string(positions);
}

int loop_on_matrix(key* k, char* positions, char c) {
    int count = 0;
    for (int m = 0; m <= positions[0] && count == 0; m++) {
        for (int n = 0; n <= positions[1] && count == 0; n++) {
            if (k->matrice[m][n] == c) {
                count++;
            }
        }
    }
    if (count == 0) {
        k->matrice[positions[0]][positions[1]] = c;
        encrease_positions(positions);
    }
}

void encrease_positions(char* positions) {
    if (positions[1] == 4) {
        positions[1] = 0;
        if (positions[0] != 4) {
            positions[0] += 1;
        }
    } else {
        positions[1] += 1;
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
#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "mem_utils.h"
#include "file.h"

key* get_key(char* keyPath) {
    key* k = (key*) malloc(sizeof(key));
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
    set_key_data(token, kd->sostituto);
    set_key_data(token, kd->speciale);
    set_key_data(token, kd->chiave);
    return kd;
}

void set_key_data(char* token, char* data_slot) {
    token = strtok(NULL, "\r\n");
    data_slot = (char*) malloc(sizeof(char) * (strlen(token)+1));
    check_string(data_slot, KEY_DATA_ERROR);
    strcpy(data_slot, token);
}

void set_matrix(key* k) {
    char* positions = (char*) calloc(2, sizeof(char));
    check_string(positions, POSITIONS_ERROR);
    for (int i = 0; i < strlen(k->kd->chiave); i++) {
        if (positions[0] <= 4) {
            insert_data_on_matrix(k->matrice, k->kd->chiave[i], positions);
        }
    }
    for (int i = 0; i < strlen(k->kd->alfabeto); i++) {
        if (positions[0] <= 4) {
            insert_data_on_matrix(k->matrice, k->kd->alfabeto[i], positions);
        }
    }
    free_string(positions);
}

void insert_data_on_matrix(char** matrix, char c, char* positions) {
    int count = 0;
    for (int i = 0; i <= positions[0] && count == 0; i++) {
        for (int j = 0; j <= positions[1] && count == 0; j++) {
            if (matrix[i][j] == c) {
                count++;
            }
        }
    }
    if (count == 0) {
        matrix[positions[0]][positions[1]] = c;
        encrease_positions(positions);
    }
}

void encrease_positions(char* positions) {
    if (positions[1] == 4) {
        positions[1] = 0;
        positions[0] += 1;
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
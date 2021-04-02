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
    insert_data_on_matrix(k->matrice, k->kd->chiave);
    insert_data_on_matrix(k->matrice, k->kd->alfabeto);
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

void insert_data_on_matrix(char** matrix, char* data) {
    for (int p = 0; p < strlen(data); p++) {
        int count = 0;
        for (int i = 0; i < 5 && count == 0; i++) {
            for (int j = 0; j < 5 && count == 0; j++) {
                if (matrix[i][j] == data[p]) {
                    count++;
                } else if (matrix[i][j] == 0 && count == 0) {
                    matrix[i][j] = data[p];
                    count++;
                }
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
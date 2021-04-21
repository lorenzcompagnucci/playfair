#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "mem_utils.h"
#include "file.h"

key* get_key(char* key_path) {
    key* k = (key*) malloc(sizeof(key));
    k->matrix = create_matrix(5, 5);
    char* buffer = read_file(key_path);
    k->kd = get_key_data(buffer);
    free_string(buffer);
    set_key(k);
    return k;
}

key_data* get_key_data(char* buffer) {
    key_data* kd = (key_data*) malloc(sizeof(key_data));
    char* token = strtok(buffer, "\r\n");
    kd->alphabet = create_string(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->alphabet, token);
    token = strtok(NULL, "\r\n");
    kd->replacement = create_string(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->replacement, token);
    token = strtok(NULL, "\r\n");
    kd->special = create_string(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->special, token);
    token = strtok(NULL, "\r\n");
    kd->keyword = create_string(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->keyword, token);
    return kd;
}

void set_key(key* key) {
    insert_data_on_matrix(key->matrix, key->kd->keyword);
    insert_data_on_matrix(key->matrix, key->kd->alphabet);
    key->replacement = key->kd->replacement[0];
    key->special = key->kd->special[0];
    set_missing_char(key);
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

void set_missing_char(key* key) {
    for (char x = 'A'; x <= 'Z'; x++) {
        key->missing = x;
        int counter = 0;
        for (int i = 0; i < 5 && counter == 0; i++) {
            for (int j = 0; j < 5 && counter == 0; j++) {
                if (x == key->matrix[i][j]) {
                    counter++;
                }
            }
        }
        if (counter == 0) {
            break;
        }
    }
}
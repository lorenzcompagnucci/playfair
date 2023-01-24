#include <stdlib.h>
#include <string.h>

#include "key.h"
#include "../memory/mem_utils.h"
#include "../file/file.h"

static Key_Key_Data_t* getKeyData(char* buffer) {
    Key_Key_Data_t* kd = (Key_Key_Data_t*) malloc(sizeof(Key_Key_Data_t));
    char* token = strtok(buffer, "\r\n");
    kd->alphabet = Memory_createString(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->alphabet, token);
    token = strtok(NULL, "\r\n");
    kd->replacement = Memory_createString(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->replacement, token);
    token = strtok(NULL, "\r\n");
    kd->special = Memory_createString(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->special, token);
    token = strtok(NULL, "\r\n");
    kd->keyword = Memory_createString(strlen(token)+1, KEY_DATA_ERROR);
    strcpy(kd->keyword, token);
    return kd;
}

static void insertDataOnMatrix(char** matrix, char* data) {
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

static void setMissingChar(Key_key_t* key) {
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

static void setKey(Key_key_t* key) {
    insertDataOnMatrix(key->matrix, key->kd->keyword);
    insertDataOnMatrix(key->matrix, key->kd->alphabet);
    key->replacement = key->kd->replacement[0];
    key->special = key->kd->special[0];
    setMissingChar(key);
}

Key_key_t* Key_getKey(char* key_path) {
    Key_key_t* k = (Key_key_t*) malloc(sizeof(Key_key_t));
    k->matrix = Memory_allocateMatrix(5, 5);
    char* buffer = File_readFile(key_path);
    k->kd = getKeyData(buffer);
    Memory_freeString(buffer);
    setKey(k);
    return k;
}
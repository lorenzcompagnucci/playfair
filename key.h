#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

#define KEY_DATA_ERROR "ERROR WHILE ALLOCATING A COMPONENT OF key_data"

typedef struct key_data {
    char* alphabet;
    char* replacement;
    char* special;
    char* keyword;
} key_data;

typedef struct key {
    key_data* kd;
    char missing;
    char replacement;
    char special;
    char** matrix;
} key;

key* get_key(char* key_path);
key_data* get_key_data(char* buffer);
void set_key(key* key);
void insert_data_on_matrix(char** matrix, char* data);
void set_missing_char(key* key);

#endif //PLAYFAIR_KEY_H
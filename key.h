#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

#define KEY_DATA_ERROR "ERROR WHILE ALLOCATING A COMPONENT OF key_data"

typedef struct key_data {
    char* alfabeto;
    char* sostituto;
    char* speciale;
    char* chiave;
} key_data;

typedef struct key {
    key_data* kd;
    char mancante;
    char sostituto;
    char speciale;
    char** matrice;
} key;

key* get_key(char* keyPath);
key_data* get_key_data(char* buffer);
void insert_data_on_matrix(char** matrix, char* data);
void set_chars(key* k);

#endif //PLAYFAIR_KEY_H
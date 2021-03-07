#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

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
void set_matrix(key* k);
void loop_on_matrix(key* k, char c);
void set_chars(key* k);
void free_key(key* k);
void free_key_data(key_data* kd);

#endif //PLAYFAIR_KEY_H
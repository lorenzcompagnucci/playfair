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
void set_matrix(key* chiavee);
void loop_on_matrix(key* chiave, char c);
void set_chars(key* chiave);
void free_key(key* key);
void free_key_data(key_data* kd);

#endif //PLAYFAIR_KEY_H
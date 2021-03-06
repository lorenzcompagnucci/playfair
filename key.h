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

key* getKey(char* keyPath);
key_data* getKeyData(char* buffer);
void setMatrix(key* chiavee);
void loopOnMatrix(key* chiave, char c);
void setChars(key* chiave);
void freeKey(key* key);
void freeKeyData(key_data* kd);

#endif //PLAYFAIR_KEY_H
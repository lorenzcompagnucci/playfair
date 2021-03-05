#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

typedef struct Key {
    char mancante;
    char sostituto;
    char speciale;
    char matrice[5][5];
} Key;

void setKey(Key* chiave, char* keyPath);
void setMatrix(Key* chiave, char* buffer);
void loopOnMatrix(Key* chiave, char c);
void setChars(Key* chiave, char* buffer);

#endif //PLAYFAIR_KEY_H
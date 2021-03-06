#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

typedef struct Key {
    char mancante;
    char sostituto;
    char speciale;
    char matrice[5][5];
} Key;

void setKey(Key* chiave, char* keyPath);
void setMatrix(Key* chiave, char* alfabeto, char* parolachiave);
void loopOnMatrix(Key* chiave, char c);
void setChars(Key* chiave, char sostituto, char speciale);

#endif //PLAYFAIR_KEY_H
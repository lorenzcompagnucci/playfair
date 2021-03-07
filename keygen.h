#ifndef PLAYFAIR_KEYGEN_H
#define PLAYFAIR_KEYGEN_H

#define OUT_KEY "ERROR WHILE CREATING THE NEW KEYFILE"

void create_key(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave);
int check_alphabet(char* alfabeto);

#endif //PLAYFAIR_KEYGEN_H
#ifndef PLAYFAIR_KEYGEN_H
#define PLAYFAIR_KEYGEN_H

#define OUT_KEY_ERROR "ERROR WHILE CREATING THE NEW KEYFILE"
#define REPLACEMENT_CHAR "REPLACEMENT CHAR"
#define SPECIAL_CHAR "SPECIAL CHAR"

void create_key(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave);
char* check_alphabet(char* alphabet);
char check_char(char* line, char* type_char);
void check_reps(int* check, char c, int i);
char* check_key(char* keyword);

#endif //PLAYFAIR_KEYGEN_H
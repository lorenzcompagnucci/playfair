#ifndef PLAYFAIR_KEYGEN_H
#define PLAYFAIR_KEYGEN_H

#define FILE_CHECK_ERROR "ERROR WHILE ALLOCATING MEMORY FOR THE OUTPUT FILE"
#define REPLACEMENT_CHAR "REPLACEMENT CHAR"
#define SPECIAL_CHAR "SPECIAL CHAR"

int Keygen_createKey(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave);

#endif //PLAYFAIR_KEYGEN_H
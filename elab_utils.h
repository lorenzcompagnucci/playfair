#ifndef PLAYFAIR_ELAB_UTILS_H
#define PLAYFAIR_ELAB_UTILS_H

#define FOUT_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

#include "key.h"

void elaborate_file(char* command, char* output_dir, char* input_file, key* key);
char* fix_missing_chars(char* message, key* key);
int create_couple(const char* message, char* couple, int i, key* key);
void find_positions(key* key, const char* couple, int positions[2][2]);

#endif //PLAYFAIR_ELAB_UTILS_H
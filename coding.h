#ifndef PLAYFAIR_CODING_H
#define PLAYFAIR_CODING_H

#define FOUT_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

#include "key.h"

void code_file(char* command, char* output_dir, char* input_file, key* key);
void print_couples(key* key, char* message, char* command, FILE* fout);
char* create_couple(const char* message, int* i, key* key);
void encode_couple(key* key, char* couple);
void decode_couple(key* key, char* couple);
void find_positions(key* key, const char* couple, int positions[2][2]);

#endif //PLAYFAIR_CODING_H
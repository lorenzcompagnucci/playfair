#ifndef PLAYFAIR_CODING_H
#define PLAYFAIR_CODING_H

#define FOUT_ERROR "ERROR WHILE OPENING THE OUTPUT FILE"

#include "key.h"

void code_file(char* command, char* output_dir, char* input_file, key* key);
void print_couples(key* key, char* message, char* command, FILE* fout);
int create_couple(char* couple, char* message, int i, key* key);
void encode_couple(key* key, char* couple);
void decode_couple(key* key, char* couple);
void find_positions(key* key, char l, int* row, int* column);

#endif //PLAYFAIR_CODING_H
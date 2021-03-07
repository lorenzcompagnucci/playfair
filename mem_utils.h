#ifndef PLAYFAIR_MEM_UTILS_H
#define PLAYFAIR_MEM_UTILS_H

void free_string(char* string);
void check_string(char* string, char* errmessage);
void free_matrix(char** matrix);
void check_matrix(char** matrix, char* errmessage);

#endif //PLAYFAIR_MEM_UTILS_H
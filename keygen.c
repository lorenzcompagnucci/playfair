#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <ctype.h>

#include "keygen.h"
#include "file.h"
#include "mem_utils.h"
#include "directory.h"

void create_key(char* path, char* alphabet, char* replace, char* special, char* keyword) {
    check_alphabet(alphabet);
    char replace_char = check_char(replace, REPLACEMENT_CHAR);
    char special_char = check_char(special, SPECIAL_CHAR);
    check_key(keyword);
    char* file = generate_key_path(path);
    FILE* fp = fopen(file, "w");
    check_file(fp, OUT_FILE_ERROR);
    free_string(file);
    fprintf(fp, "%s\r\n%c\r\n%c\r\n%s\r\n", alphabet, replace_char, special_char, keyword);
    fflush(fp);
    fclose(fp);
}

void check_alphabet(char* alphabet) {
    if (strlen(alphabet) != 25) {
        printf("THE ALPHABET MUST BE MADE OF 25 CHARS.\n");
        exit(0);
    }
    char* check = (char*) calloc(25, sizeof(char));
    check_string(check, ALPHABET_CHECK_ERROR);
    for (int i = 0; i < 25; i++) {
        check_reps(check, alphabet[i], i);
    }
    free_string(check);
}

void check_reps(char* check, char c, int i) {
    char a = toupper(c);
    if (a < 'A' || a > 'Z') {
        printf("A CHARCTER OF THE ALPHABET IS NOT A LETTER.\n");
        exit(0);
    }
    for (int j = 0; j < 25; ++j) {
        if (check[j] == a) {
            printf("THE ALPHABET HAS TO CONTAIN 25 DIFFERENT CHARACTERS.\n");
            exit(0);
        }
    }
    check[i] = a;
}

char check_char(char* line, char* type_char) {
    if (strlen(line) != 1) {
        printf("%s HAS TO BE JUST ONE CHAR.\n", type_char);
        exit(0);
    }
    char c = toupper(line[0]);
    if (c < 'A' || c > 'Z') {
        printf("%s IS NOT A CHARACTER.\n", type_char);
        exit(0);
    }
    return c;
}

void check_key(char* keyword) {
    for (int i = 0; i < strlen(keyword); i++) {
        char c = toupper(keyword[i]);
        if (c < 'A' || c > 'Z') {
            printf("A CHAR OF THE KEYWORD IS NOT A LETTER.\n");
            exit(0);
        }
    }
}

char* generate_key_path(char* path) {
    char *file = (char*) malloc(sizeof(char) * (strlen(path)+1));
    check_string(file, FILE_CHECK_ERROR);
    strcpy(file, path);
    check_directory(dirname(path));
    return file;
}
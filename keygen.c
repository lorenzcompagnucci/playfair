#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "keygen.h"
#include "file.h"

void create_key(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave) {
    char* alphabet = check_alphabet(alfabeto);
    char replace_char = check_char(sostituto, REPLACEMENT_CHAR);
    char special_char = check_char(speciale, SPECIAL_CHAR);
    char* keyword = check_key(chiave);
    FILE* fp = fopen(path, "w");
    check_file(fp, OUT_KEY_ERROR);
    fprintf(fp, "%s\r\n%c\r\n%c\r\n%s\r\n", alphabet, replace_char, special_char, keyword);
    fflush(fp);
    fclose(fp);
}

char* check_alphabet(char* alphabet) {
    if (strlen(alphabet) != 25) {
        printf("THE ALPHABET MUST BE MADE OF 25 CHARS.\n");
        exit(0);
    }
    int check[25];
    for (int i = 0; i < 25; i++) {
        check[i] = 0;
        check_reps(check, alphabet[i], i);
    }
    return alphabet;
}

void check_reps(int* check, char c, int i) {
    char a = toupper(c);
    if (a < 'A' || a > 'Z') {
        printf("A CHARCTER OF THE ALPHABET IS NOT A LETTER.\n");
        exit(0);
    }
    if (check[i] == 1) {
        printf("THE ALPHABET HAS TO CONTAIN 25 DIFFERENT CHARACTERS.\n");
        exit(0);
    }
    check[i] = 1;
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

char* check_key(char* keyword) {
    for (int i = 0; i < strlen(keyword); i++) {
        char c = toupper(keyword[i]);
        if (c < 'A' || c > 'Z') {
            printf("A CHAR OF THE KEYWORD IS NOT A LETTER.\n");
            exit(0);
        }
    }
    return keyword;
}
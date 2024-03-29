#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <ctype.h>

#include "keygen.h"
#include "../file/file.h"
#include "../memory/mem_utils.h"
#include "../file/directory.h"

static void checkAlphabet(char* alphabet) {
    if (strlen(alphabet) != 25) {
        printf("THE ALPHABET MUST BE MADE OF 25 CHARS.\n");
        exit(0);
    }
    for (int i = 0; i < strlen(alphabet); ++i) {
        char c = toupper(alphabet[i]);
        if (c >= 'A' || c <= 'Z') {
            for (int j = 0; j < strlen(alphabet); ++j) {
                if (i != j && c == toupper(alphabet[j])) {
                    printf("CHAR '%c' IS PRESENT MORE THAN ONCE.\n", c);
                    exit(0);
                }
            }
        } else {
            printf("CHAR IN POS %d OF THE ALPHABET IS NOT A CHARACTER.\n", i+1);
            exit(0);
        }
    }
}

static char checkChar(char* line, char* type_char) {
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

static void checkKey(char* keyword) {
    for (int i = 0; i < strlen(keyword); i++) {
        char c = toupper(keyword[i]);
        if (c < 'A' || c > 'Z') {
            printf("A CHAR OF THE KEYWORD IS NOT A LETTER.\n");
            exit(0);
        }
        keyword[i] = c;
    }
}

static char* generateKeyPath(char* path) {
    char *file = (char*) malloc(sizeof(char) * (strlen(path)+1));
    Memory_checkString(file, FILE_CHECK_ERROR);
    strcpy(file, path);
    Directory_checkDirectory(dirname(path));
    return file;
}

int Keygen_createKey(char* path, char* alphabet, char* replace, char* special, char* keyword) {
    checkAlphabet(alphabet);
    char replace_char = checkChar(replace, REPLACEMENT_CHAR);
    char special_char = checkChar(special, SPECIAL_CHAR);
    checkKey(keyword);
    char* file = generateKeyPath(path);
    FILE* fp = fopen(file, "w");
    File_checkFile(fp);
    Memory_freeString(file);
    fprintf(fp, "%s\r\n%c\r\n%c\r\n%s\r\n", alphabet, replace_char, special_char, keyword);
    fflush(fp);
    fclose(fp);
    return 1;
}
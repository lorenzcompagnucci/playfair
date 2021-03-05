#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "keygen.h"

void createKey(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave) {
    assert(checkAlphabet(alfabeto) == 1);
    FILE* fp = fopen(path, "w");
    if (fp == NULL) {
        perror("ERROR WHILE CREATING THE NEW KEYFILE");
        exit(0);
    }
    fprintf(fp, "%s\r\n%c\r\n%c\r\n%s\r\n", alfabeto, sostituto[0], speciale[0], chiave);
    fflush(fp);
    fclose(fp);
}

int checkAlphabet(char* alfabeto) {
    if (strlen(alfabeto) != 25) {
        printf("THE ALPHABET MUST BE MADE OF 25 CHARS.\n");
        return -1;
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (j != i && alfabeto[i] == alfabeto[j]) {
                printf("CHARACTER '%c' IS PRESENT MORE THAN ONCE.\n", alfabeto[i]);
                return -1;
            }
        }
    }
    return 1;
}
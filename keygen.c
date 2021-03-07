#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "keygen.h"
#include "file.h"

void create_key(char* path, char* alfabeto, char* sostituto, char* speciale, char* chiave) {
    assert(check_alphabet(alfabeto) == 1);
    FILE* fp = fopen(path, "w");
    check_file(fp, OUT_KEY_ERROR);
    fprintf(fp, "%s\r\n%c\r\n%c\r\n%s\r\n", alfabeto, sostituto[0], speciale[0], chiave);
    fflush(fp);
    fclose(fp);
}

int check_alphabet(char* alfabeto) {
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
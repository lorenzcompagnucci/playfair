#include <stdio.h>
#include <string.h>

#include "coding.h"
#include "file.h"
#include "directory.h"
#include "mem_utils.h"

void code_file(key* chiave, char* outputDir, char* inputFile, char* command) {
    char* message = read_file(inputFile);
    char* outputPath = get_directory(outputDir, inputFile, command);
    FILE* fout = fopen(outputPath, "w");
    check_file(fout, OUT_FILE_ERROR);
    free_string(outputPath);
    int rows = strlen(message)*2;
    char** couples = divide_couples(chiave, message, rows);
    code_couple(chiave, couples, command);
    for (int i = 0; couples[i][0] != 0; i++) {
        fprintf(fout, "%s ", couples[i]);
        fflush(fout);
    }
    fclose(fout);
    free_string(message);
    free_matrix(couples, rows);
}

char** divide_couples(key* chiave, char* message, int rows) {
    char** couples = create_matrix(rows, 2);
    int r = 0;
    for (int i = 0; i < strlen(message); i++) {
        create_couple(message, chiave, &i, couples[r]);
    }
    return couples;
}

void create_couple(char* message, key* chiave, int *i, char* couple) {
    couple[0] = message[*i];
    couple[1] = message[*i+1];
    for (int j = 0; j < strlen(couple); ++j) {
        if (couple[j] == chiave->mancante) {
            couple[j] = chiave->sostituto;
        }
    }
    if (couple[0] != couple[1] && couple[1] != '\0') {
        *i += 1;
    } else {
        couple[1] = chiave->speciale;
    }
}

void code_couple(key* chiave, char** couples, char* command) {
    for (int i = 0; couples[i][0] != 0; i++) {
        if (strcmp(command, "encode") == 0) {
            encode_couple(chiave, couples[i]);
        } else {
            decode_couple(chiave, couples[i]);
        }
    }
}

void encode_couple(key* chiave, char* couple) {
    int r1 = -1, c1, r2 = -1, c2;
    find_positions(chiave, couple[0], &r1, &c1);
    find_positions(chiave, couple[1], &r2, &c2);
    if (r1 == r2) { // stessa riga
        if (c1 == 4) {
            couple[0] = chiave->matrice[r1][0];
            couple[1] = chiave->matrice[r2][c2+1];
        } else if (c2 == 4) {
            couple[0] = chiave->matrice[r1][c1+1];
            couple[1] = chiave->matrice[r2][0];
        } else {
            couple[0] = chiave->matrice[r1][c1+1];
            couple[1] = chiave->matrice[r2][c2+1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 4) {
            couple[0] = chiave->matrice[0][c1];
            couple[1] = chiave->matrice[r2+1][c2];
        } else if (r2 == 4) {
            couple[0] = chiave->matrice[r1+1][c1];
            couple[1] = chiave->matrice[0][c2];
        } else {
            couple[0] = chiave->matrice[r1+1][c1];
            couple[1] = chiave->matrice[r2+1][c2];
        }
    } else { // rettangolo
        couple[0] = chiave->matrice[r1][c2];
        couple[1] = chiave->matrice[r2][c1];
    }
}

void decode_couple(key* chiave, char* couple) {
    int r1 = -1, c1, r2 = -1, c2;
    find_positions(chiave, couple[0], &r1, &c1);
    find_positions(chiave, couple[1], &r2, &c2);
    if (r1 == r2) { // stessa riga
        if (c1 == 0) {
            couple[0] = chiave->matrice[r1][4];
            couple[1] = chiave->matrice[r2][c2-1];
        } else if (c2 == 0) {
            couple[0] = chiave->matrice[r1][c1-1];
            couple[1] = chiave->matrice[r2][4];
        } else {
            couple[0] = chiave->matrice[r1][c1-1];
            couple[1] = chiave->matrice[r2][c2-1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 0) {
            couple[0] = chiave->matrice[4][c1];
            couple[1] = chiave->matrice[r2-1][c2];
        } else if (r2 == 0) {
            couple[0] = chiave->matrice[r1-1][c1];
            couple[1] = chiave->matrice[4][c2];
        } else {
            couple[0] = chiave->matrice[r1-1][c1];
            couple[1] = chiave->matrice[r2-1][c2];
        }
    } else { // rettangolo
        couple[0] = chiave->matrice[r1][c2];
        couple[1] = chiave->matrice[r2][c1];
    }
}

void find_positions(key* chiave, char l, int* riga, int* colonna) {
    for (int i = 0; i < 5 && *riga == -1; ++i) {
        for (int j = 0; j < 5 && *riga == -1; ++j) {
            if (chiave->matrice[i][j] == l) {
                *riga = i;
                *colonna = j;
            }
        }
    }
}
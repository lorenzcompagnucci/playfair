#include <stdio.h>
#include <string.h>

#include "coding.h"
#include "file.h"
#include "directory.h"
#include "mem_utils.h"

void code_file(char* command, char* outputDir, char* inputFile, key* chiave) {
    char* message = read_file(inputFile);
    char* outputPath = get_directory(outputDir, inputFile, command);
    FILE* fout = fopen(outputPath, "w");
    check_file(fout, CODED_FILE_ERROR);
    free_string(outputPath);
    print_couples(chiave, message, command, fout);
    fclose(fout);
    free_string(message);
}

void print_couples(key* chiave, char* message, char* command, FILE* fout) {
    int i = 0;
    while (i < strlen(message)) {
        char couple[3];
        i += create_couple(couple, message, i, chiave);
        if (strcmp(command, "encode") == 0) {
            encode_couple(chiave, couple);
        } else {
            decode_couple(chiave, couple);
        }
        fprintf(fout, "%s ", couple);
        fflush(fout);
    }
}

int create_couple(char* couple, char* message, int i, key* chiave) {
    couple[0] = message[i];
    couple[1] = message[i+1];
    for (int j = 0; j < strlen(couple); j++) {
        if (couple[j] == chiave->mancante) {
            couple[j] = chiave->sostituto;
        }
    }
    if (couple[0] != couple[1] && couple[1] != '\0') {
        return 2;
    } else {
        couple[1] = chiave->speciale;
        return 1;
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
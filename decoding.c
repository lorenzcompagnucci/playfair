#include <stdio.h>
#include <string.h>

#include "decoding.h"
#include "file.h"
#include "directory.h"
#include "mem_utils.h"
#include "elab_utils.h"

void decode_file(key* chiave, char* outputDir, char* inputFile) {
    char* message = read_file(inputFile);
    char* outputPath = get_directory(outputDir, inputFile, ".dec");
    FILE* fout = fopen(outputPath, "w");
    check_file(fout, OUT_FILE_ERROR);
    free_string(outputPath);
    char l1, l2;
    for (int i = 0; i < strlen(message); i++) {
        create_couple(message, chiave, &l1, &l2, &i);
        decode_couple(chiave, &l1, &l2);
        fprintf(fout, "%c%c ", l1, l2);
        fflush(fout);
    }
    fclose(fout);
    free_string(message);
}

void decode_couple(key* chiave, char* l1, char* l2) {
    int r1 = -1, c1, r2 = -1, c2;
    find_positions(chiave, l1, &r1, &c1);
    find_positions(chiave, l2, &r2, &c2);
    if (r1 == r2) { // stessa riga
        if (c1 == 0) {
            *l1 = chiave->matrice[r1][4];
            *l2 = chiave->matrice[r2][c2-1];
        } else if (c2 == 0) {
            *l1 = chiave->matrice[r1][c1-1];
            *l2 = chiave->matrice[r2][4];
        } else {
            *l1 = chiave->matrice[r1][c1-1];
            *l2 = chiave->matrice[r2][c2-1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 0) {
            *l1 = chiave->matrice[4][c1];
            *l2 = chiave->matrice[r2-1][c2];
        } else if (r2 == 0) {
            *l1 = chiave->matrice[r1-1][c1];
            *l2 = chiave->matrice[4][c2];
        } else {
            *l1 = chiave->matrice[r1-1][c1];
            *l2 = chiave->matrice[r2-1][c2];
        }
    } else { // rettangolo
        *l1 = chiave->matrice[r1][c2];
        *l2 = chiave->matrice[r2][c1];
    }
}
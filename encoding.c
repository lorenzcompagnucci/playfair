#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encoding.h"
#include "elabutils.h"
#include "file.h"
#include "directory.h"

void encodeFile(Key chiave, char* outputDir, char* inputFile) {
    char* message = readFile(inputFile);
    char* outputPath = getDirectory(outputDir, inputFile, ".pf");
    FILE* fout = fopen(outputPath, "w");
    if (fout == NULL) {
        perror("ERROR WHILE OPENING THE OUTPUT FILE");
        exit(0);
    }
    free(outputPath);
    outputPath = NULL;
    fixMissingChars(chiave, message);
    encodeMessagge(chiave, message, fout);
    fclose(fout);
    free(message);
    message = NULL;
}

void encodeMessagge(Key chiave, char* message, FILE* fout) {
    for (int i = 0; i < strlen(message); i++) {
        char l1 = message[i];
        char l2 = message[i+1];
        if (l1 != l2 && l2 != '\0') {
            i++;
        } else {
            l2 = chiave.speciale;
        }
        encodeCouple(chiave, &l1, &l2);
        fprintf(fout, "%c%c ", l1, l2);
        fflush(fout);
    }
}

void encodeCouple(Key chiave, char *l1, char *l2) {
    int r1 = -1, c1, r2 = -1, c2;
    findPositions(chiave, l1, &r1, &c1);
    findPositions(chiave, l2, &r2, &c2);
    if (r1 == r2) { // stessa riga
        if (c1 == 4) {
            *l1 = chiave.matrice[r1][0];
            *l2 = chiave.matrice[r2][c2+1];
        } else if (c2 == 4) {
            *l1 = chiave.matrice[r1][c1+1];
            *l2 = chiave.matrice[r2][0];
        } else {
            *l1 = chiave.matrice[r1][c1+1];
            *l2 = chiave.matrice[r2][c2+1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 4) {
            *l1 = chiave.matrice[0][c1];
            *l2 = chiave.matrice[r2+1][c2];
        } else if (r2 == 4) {
            *l1 = chiave.matrice[r1+1][c1];
            *l2 = chiave.matrice[0][c2];
        } else {
            *l1 = chiave.matrice[r1+1][c1];
            *l2 = chiave.matrice[r2+1][c2];
        }
    } else { // rettangolo
        *l1 = chiave.matrice[r1][c2];
        *l2 = chiave.matrice[r2][c1];
    }
}
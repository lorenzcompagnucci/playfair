#include <stdio.h>
#include <string.h>

#include "encoding.h"
#include "elab_utils.h"

void encode_message(key* key, char* message, FILE* fout) {
    int i = 0;
    char couple[3];
    message = fix_missing_chars(message, key);
    while (i < strlen(message)) {
        i += create_couple(message, couple, i, key);
        encode_couple(key, couple);
        fprintf(fout, "%s ", couple);
        fflush(fout);
    }
}

void encode_couple(key* key, char* couple) {
    int positions[2][2];
    find_positions(key, couple, positions);
    int r1 = positions[0][0];
    int c1 = positions[0][1];
    int r2 = positions[1][0];
    int c2 = positions[1][1];
    if (r1 == r2) { // stessa riga
        if (c1 == 4) {
            couple[0] = key->matrix[r1][0];
            couple[1] = key->matrix[r2][c2+1];
        } else if (c2 == 4) {
            couple[0] = key->matrix[r1][c1+1];
            couple[1] = key->matrix[r2][0];
        } else {
            couple[0] = key->matrix[r1][c1+1];
            couple[1] = key->matrix[r2][c2+1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 4) {
            couple[0] = key->matrix[0][c1];
            couple[1] = key->matrix[r2+1][c2];
        } else if (r2 == 4) {
            couple[0] = key->matrix[r1+1][c1];
            couple[1] = key->matrix[0][c2];
        } else {
            couple[0] = key->matrix[r1+1][c1];
            couple[1] = key->matrix[r2+1][c2];
        }
    } else { // rettangolo
        couple[0] = key->matrix[r1][c2];
        couple[1] = key->matrix[r2][c1];
    }
}
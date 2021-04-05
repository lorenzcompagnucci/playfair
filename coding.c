#include <stdio.h>
#include <string.h>

#include "coding.h"
#include "file.h"
#include "directory.h"
#include "mem_utils.h"

void code_file(char* command, char* output_dir, char* input_file, key* key) {
    char* message = read_file(input_file);
    char* outputPath = get_directory(output_dir, input_file, command);
    FILE* fout = fopen(outputPath, "w");
    check_file(fout, FOUT_ERROR);
    free_string(outputPath);
    print_couples(key, message, command, fout);
    fclose(fout);
    free_string(message);
}

void print_couples(key* key, char* message, char* command, FILE* fout) {
    int i = 0;
    while (i < strlen(message)) {
        char couple[3];
        i += create_couple(couple, message, i, key);
        if (strcmp(command, "encode") == 0) {
            encode_couple(key, couple);
        } else {
            decode_couple(key, couple);
        }
        fprintf(fout, "%s ", couple);
        fflush(fout);
    }
}

int create_couple(char* couple, const char* message, int i, key* key) {
    couple[0] = message[i];
    couple[1] = message[i+1];
    for (int j = 0; j < strlen(couple); j++) {
        if (couple[j] == key->missing) {
            couple[j] = key->replacement;
        }
    }
    if (couple[0] == couple[1] || couple[1] == '\0') {
        couple[1] = key->special;
        return 1;
    }
    return 2;
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

void decode_couple(key* key, char* couple) {
    int positions[2][2];
    find_positions(key, couple, positions);
    int r1 = positions[0][0];
    int c1 = positions[0][1];
    int r2 = positions[1][0];
    int c2 = positions[1][1];
    if (r1 == r2) { // stessa riga
        if (c1 == 0) {
            couple[0] = key->matrix[r1][4];
            couple[1] = key->matrix[r2][c2-1];
        } else if (c2 == 0) {
            couple[0] = key->matrix[r1][c1-1];
            couple[1] = key->matrix[r2][4];
        } else {
            couple[0] = key->matrix[r1][c1-1];
            couple[1] = key->matrix[r2][c2-1];
        }
    } else if (c1 == c2) { // stessa colonna
        if (r1 == 0) {
            couple[0] = key->matrix[4][c1];
            couple[1] = key->matrix[r2-1][c2];
        } else if (r2 == 0) {
            couple[0] = key->matrix[r1-1][c1];
            couple[1] = key->matrix[4][c2];
        } else {
            couple[0] = key->matrix[r1-1][c1];
            couple[1] = key->matrix[r2-1][c2];
        }
    } else { // rettangolo
        couple[0] = key->matrix[r1][c2];
        couple[1] = key->matrix[r2][c1];
    }
}

void find_positions(key* key, const char* couple, int positions[2][2]) {
    positions[0][0] = -1;
    positions[1][0] = -1;
    for (int i = 0; i < 5 && (positions[0][0] == -1 || positions[1][0] == -1); i++) {
        for (int j = 0; j < 5 && (positions[0][0] == -1 || positions[1][0] == -1); j++) {
            if (key->matrix[i][j] == couple[0]) {
                positions[0][0] = i;
                positions[0][1] = j;
            } else if (key->matrix[i][j] == couple[1]) {
                positions[1][0] = i;
                positions[1][1] = j;
            }
        }
    }
}
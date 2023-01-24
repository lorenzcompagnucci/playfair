#include <string.h>

#include "playfair.h"
#include "../key/key.h"
#include "../file/file.h"
#include "../file/directory.h"
#include "../memory/mem_utils.h"

static char* fixMissingChars(char* message, Key_key_t* key) {
    char* new_message = message;
    for (int i = 0; i < strlen(new_message); i++) {
        if (new_message[i] == key->missing) {
            new_message[i] = key->replacement;
        }
    }
    return new_message;
}

static int createCouple(const char* message, char* couple, int i, Key_key_t* key) {
    couple[0] = message[i];
    couple[1] = message[i+1];
    if (couple[0] == couple[1] || couple[1] == '\0') {
        couple[1] = key->special;
        return 1;
    }
    return 2;
}

static void findPositions(Key_key_t* key, const char* couple, int positions[2][2]) {
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

void encodeCouple(Key_key_t* key, char* couple) {
    int positions[2][2];
    findPositions(key, couple, positions);
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



static void decodeCouple(Key_key_t* key, char* couple) {
    int positions[2][2];
    findPositions(key, couple, positions);
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

static void decodeMessage(Key_key_t* key, char* message, FILE* fout) {
    int i = 0;
    char couple[3];
    message = fixMissingChars(message, key);
    while (i < strlen(message)) {
        i += createCouple(message, couple, i, key);
        decodeCouple(key, couple);
        fprintf(fout, "%s ", couple);
        fflush(fout);
    }
}

static void encodeMessage(Key_key_t* key, char* message, FILE* fout) {
    int i = 0;
    char couple[3];
    message = fixMissingChars(message, key);
    while (i < strlen(message)) {
        i += createCouple(message, couple, i, key);
        encodeCouple(key, couple);
        fprintf(fout, "%s ", couple);
        fflush(fout);
    }
}

static void elaborate(char* command, char* output_dir, char* input_file, Key_key_t* key) {
    char* message = File_readFile(input_file);
    char* outputPath = Directory_getDirectory(output_dir, input_file, command);
    FILE* fout = fopen(outputPath, "w");
    File_checkFile(fout);
    Memory_freeString(outputPath);
    if (strcmp(command, "encode") == 0) {
        encodeMessage(key, message, fout);
    } else {
        decodeMessage(key, message, fout);
    }
    fclose(fout);
    Memory_freeString(message);
}

int Playfair_run(char **argv, int argc) {
    Key_key_t* key = Key_getKey(argv[2]);
    for (int i = 4; i < argc; i++) {
        elaborate(argv[1], argv[3], argv[i], key);
    }
    Memory_freeKey(key);
    return 1;
}
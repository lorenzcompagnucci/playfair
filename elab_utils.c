#include <string.h>

#include "elab_utils.h"
#include "file.h"
#include "directory.h"
#include "mem_utils.h"
#include "encoding.h"
#include "decoding.h"

void elaborate_file(char* command, char* output_dir, char* input_file, key* key) {
    char* message = read_file(input_file);
    char* outputPath = get_directory(output_dir, input_file, command);
    FILE* fout = fopen(outputPath, "w");
    check_file(fout, FOUT_ERROR);
    free_string(outputPath);
    if (strcmp(command, "encode") == 0) {
        encode_message(key, message, fout);
    } else {
        decode_message(key, message, fout);
    }
    fclose(fout);
    free_string(message);
}

char* fix_missing_chars(char* message, key* key) {
    char* new_message = message;
    for (int i = 0; i < strlen(new_message); ++i) {
        if (new_message[i] == key->missing) {
            new_message[i] = key->replacement;
        }
    }
    return new_message;
}

int create_couple(const char* message, char* couple, int i, key* key) {
    couple[0] = message[i];
    couple[1] = message[i+1];
    if (couple[0] == couple[1] || couple[1] == '\0') {
        couple[1] = key->special;
        return 1;
    } else {
        return 2;
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
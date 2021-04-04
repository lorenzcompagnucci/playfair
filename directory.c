#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <ftw.h>
#include <dirent.h>
#include <errno.h>

#include "directory.h"
#include "mem_utils.h"

char* get_directory(char* output_dir, char* input_file, char* command) {
    if (strcmp(command, "encode") == 0) {
        return create_directory(output_dir, input_file, ".pf");
    } else {
        return create_directory(output_dir, input_file, ".dec");
    }
}

char* create_directory(char* output_dir, char* input_file, char* format) {
    char *outputFile = (char*) malloc((strlen(basename(input_file)) + strlen(format) + 1) * sizeof(char));
    check_string(outputFile, FILE_O);
    strcpy(outputFile, basename(input_file));
    modify_extension(outputFile, format);
    check_directory(output_dir);
    char* outputPath = (char*) malloc((strlen(output_dir) + 1) * sizeof(char) + sizeof(outputFile));
    check_string(outputPath, DIR_O);
    strcpy(outputPath, output_dir);
    strcat(outputPath, "/");
    strcat(outputPath, outputFile);
    free_string(outputFile);
    return outputPath;
}

void modify_extension(char* file, char* extension) {
    int length = strlen(file), lastdot = 0;
    for (int i = 0; i < length; i++) {
        if (file[i] == '.') {
            lastdot = i;
        }
    }
    if (lastdot != 0) {
        for (int j = length-1; j >= lastdot; j--) {
            file[j] = '\0';
        }
    }
    strcat(file, extension);
    strcat(file, "\0");
}

void check_directory(char* directory) {
    DIR* d = opendir(directory);
    if (ENOENT == errno) {
        mkdir(directory, 0777);
    }
    closedir(d);
}
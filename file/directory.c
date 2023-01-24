#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <ftw.h>
#include <dirent.h>
#include <errno.h>

#include "directory.h"
#include "../memory/mem_utils.h"

static void modifyExtension(char* file, char* extension) {
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

void Directory_checkDirectory(char* directory) {
    DIR* d = opendir(directory);
    if (ENOENT == errno) {
        mkdir(directory, 0777);
    }
    closedir(d);
}

static char* createDirectory(char* output_dir, char* input_file, char* format) {
    char *outputFile = Memory_createString(strlen(basename(input_file)) + strlen(format) + 1, FILE_O);
    strcpy(outputFile, basename(input_file));
    modifyExtension(outputFile, format);
    Directory_checkDirectory(output_dir);
    char* outputPath = Memory_createString(strlen(output_dir) + strlen(outputFile) + 1, DIR_O);
    strcpy(outputPath, output_dir);
    strcat(outputPath, "/");
    strcat(outputPath, outputFile);
    Memory_freeString(outputFile);
    return outputPath;
}

char* Directory_getDirectory(char* output_dir, char* input_file, char* command) {
    if (strcmp(command, "encode") == 0) {
        return createDirectory(output_dir, input_file, ".pf");
    } else {
        return createDirectory(output_dir, input_file, ".dec");
    }
}
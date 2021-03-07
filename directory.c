#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <ftw.h>
#include <dirent.h>
#include <errno.h>

#include "directory.h"
#include "file.h"

char* get_directory(char* outputDir, char* inputFile, char* format) {
    char *outputFile = (char*) malloc((strlen(basename(inputFile))+5) * sizeof(char));
    check_malloc(outputFile, FILE_O);
    strcpy(outputFile, basename(inputFile));
    modify_extension(outputFile, format);
    check_directory(outputDir);
    char* outputPath = (char*) malloc((strlen(outputDir)+1)*sizeof(char) + sizeof(outputFile));
    check_malloc(outputPath, DIR_O);
    strcat(strcat(strcpy(outputPath, outputDir), "/"), outputFile);
    free(outputFile);
    outputFile = NULL;
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
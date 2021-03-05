#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <ftw.h>
#include <dirent.h>
#include <errno.h>

#include "directory.h"

char* getDirectory(char* outputDir, char* inputFile, char* format) {
    char *outputFile = (char*) malloc((strlen(basename(inputFile))+5) * sizeof(char));
    if (outputFile == NULL) {
        perror("ERROR WHILE CREATING THE OUTPUT FILE");
        exit(0);
    }
    strcpy(outputFile, basename(inputFile));
    modifyExtension(outputFile, format);
    checkDirectory(outputDir);
    char* outputPath = (char*) malloc((strlen(outputDir)+1)*sizeof(char) + sizeof(outputFile));
    if (outputPath == NULL) {
        perror("ERROR WHILE CREATING THE OUTPUT DIRECTORY");
        exit(0);
    }
    strcat(strcat(strcpy(outputPath, outputDir), "/"), outputFile);
    free(outputFile);
    outputFile = NULL;
    return outputPath;
}

void modifyExtension(char* file, char* extension) {
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

void checkDirectory(char* directory) {
    DIR* d = opendir(directory);
    if (ENOENT == errno) {
        mkdir(directory, 0777);
    }
    closedir(d);
}
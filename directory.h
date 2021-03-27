#ifndef PLAYFAIR_DIRECTORY_H
#define PLAYFAIR_DIRECTORY_H

#define FILE_O "ERROR WHILE MODIFYING THE OUTPUT FILE"
#define DIR_O "ERROR WHILE CREATING THE OUTPUT DIRECTORY"

char* get_directory(char* outputDir, char* inputFile, char* command);
char* create_directory(char* outputDir, char* inputFile, char* format);
void modify_extension(char* file, char* extension);
void check_directory(char* directory);

#endif //PLAYFAIR_DIRECTORY_H
#ifndef PLAYFAIR_DIRECTORY_H
#define PLAYFAIR_DIRECTORY_H

#define FILE_O "ERROR WHILE MODIFYING THE OUTPUT FILE"
#define DIR_O "ERROR WHILE CREATING THE OUTPUT DIRECTORY"

void Directory_checkDirectory(char* directory);
char* Directory_getDirectory(char* output_dir, char* input_file, char* command);

#endif //PLAYFAIR_DIRECTORY_H
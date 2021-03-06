#include <stdio.h>
#include <string.h>

#include "keygen.h"
#include "key.h"
#include "encoding.h"
#include "decoding.h"

void printCommands() {
    printf("playfair (encode/decode) chiave outputDir file1 file2..\n");
    printf("playfair createkey path alfabeto sostituto speciale parolachiave.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("There must be at least 5 args, but only %d were given.\n", argc);
        printCommands();
        return 0;
    }
    if (strcmp(argv[1], "createkey") == 0) {
        createKey(argv[2], argv[3], argv[4], argv[5], argv[6]);
        return 1;
    }
    if (strcmp(argv[1], "encode") == 0) {
        key* key = getKey(argv[2]);
        for (int i = 4; i < argc; ++i) {
            encodeFile(key, argv[3], argv[i]);
        }
        freeKey(key);
        return 1;
    } else if (strcmp(argv[1], "decode") == 0) {
        key* key = getKey(argv[2]);
        for (int i = 4; i < argc; ++i) {
            decodeFile(key, argv[3], argv[i]);
        }
        freeKey(key);
        return 1;
    }
    printf("Unknown command '%s'\n", argv[1]);
    printCommands();
    return 0;
}
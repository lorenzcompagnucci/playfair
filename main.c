#include <stdio.h>
#include <string.h>

#include "key/keygen.h"
#include "coding/playfair.h"

static void printCommands() {
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
        return Keygen_createKey(argv[2], argv[3], argv[4], argv[5], argv[6]);
    } else if (strcmp(argv[1], "encode") == 0 || (strcmp(argv[1], "decode") == 0)) {
        return Playfair_run(argv, argc);
    }
    printf("Unknown command '%s'\n", argv[1]);
    printCommands();
    return 0;
}
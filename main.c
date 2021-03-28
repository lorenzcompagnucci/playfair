#include <stdio.h>
#include <string.h>

#include "keygen.h"
#include "key.h"
#include "coding.h"
#include "mem_utils.h"

void print_commands() {
    printf("playfair (encode/decode) chiave outputDir file1 file2..\n");
    printf("playfair createkey path alfabeto sostituto speciale parolachiave.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("There must be at least 5 args, but only %d were given.\n", argc);
        print_commands();
        return 0;
    }
    if (strcmp(argv[1], "createkey") == 0) {
        create_key(argv[2], argv[3], argv[4], argv[5], argv[6]);
        return 1;
    }
    if (strcmp(argv[1], "encode") == 0 || strcmp(argv[1], "decode") == 0) {
        key* key = get_key(argv[2]);
        for (int i = 4; i < argc; i++) {
            code_file(argv[1], argv[3], argv[i], key);
        }
        free_key(key);
        return 1;
    }
    printf("Unknown command '%s'\n", argv[1]);
    print_commands();
    return 0;
}
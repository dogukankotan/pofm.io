#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "iodit.h"

void main(int argc, char *argv[]) {
    if (argc == 2) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                help();
                return;
            }
        }
        puts("Unsupported argument. Please use -h or --help for usage.");
    }
    else if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
            if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--append") == 0) {
                append(argv[1]);
                return;
            }
            else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--insert") == 0) {
                insert(argv[1]);
                return;
            }
            else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--destroy") == 0) {
                destroy(argv[1]);
                return;
            }
            else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--show") == 0) {
                show(argv[1]);
                return;
            }
            else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                help();
                return;
            }
        }
        puts("Unsupported argument. Please use -h or --help for usage.");
    }

    else {
        puts("Please give argument or for usage use -h or --help.");
    }
}

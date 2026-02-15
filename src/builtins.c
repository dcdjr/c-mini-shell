#include "builtins.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int handle_builtin(char** argv) {
    if (!argv || !argv[0]) return 0;

    if (strcmp(argv[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(argv[0], "cd") == 0) {
        char* path = argv[1];
        
        if (!path) {
            path = getenv("HOME");
            if (!path) {
                fprintf(stderr, "cd: HOME not set\n");
                return 1;
            }
        }

        if (chdir(path) != 0) {
            perror("cd");
        }

        return 1;
    }

    return 0;
}

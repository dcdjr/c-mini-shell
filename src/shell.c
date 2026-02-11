#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

void shell_loop(void) {
    char *line = NULL;
    size_t len = 0;

    while (1) {
        printf("%s", "myshell> ");
        fflush(stdout);

        if (getline(&line, &len, stdin) == -1) {
            break;
        }


    }

    free(line);
}

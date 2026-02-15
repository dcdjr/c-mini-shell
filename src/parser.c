#include "parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char **parse_args(char *line) {
    if (!line) return NULL;

    // Strip newline
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    // Count tokens
    size_t tok_count = 0;
    char* copy = strdup(line);
    if (!copy) return NULL;
    char* saveptr1;
    char* token;

    token = strtok_r(copy, " \t", &saveptr1);
    while (token != NULL) {
        tok_count++;
        token = strtok_r(NULL, " \t", &saveptr1);
    }

    free(copy);
    copy = NULL;

    if (tok_count == 0) return NULL;
    // Allocate argv
    char** argv = (char**)malloc((tok_count + 1) * sizeof(char*));
    if (!argv) return NULL;
    // Tokenize
    size_t i = 0;
    char* saveptr2;
    token = strtok_r(line, " \t", &saveptr2);
    while (token) {
        argv[i] = strdup(token);
        // handle strdup failure safely
        if (!argv[i]) {
            for (size_t j = 0; j < i; j++) {
                free(argv[j]);
            }
            free(argv);
            return NULL;
        }
        token = strtok_r(NULL, " \t", &saveptr2);
        i++;
    }
    // NULL terminate argv
    argv[tok_count] = NULL;
    // Return array of args
    return argv;
}

void free_args(char **argv) {
    if (!argv) return;

    for (size_t i = 0; argv[i] != NULL; i++) {
        free(argv[i]);
    }
    free(argv);
}

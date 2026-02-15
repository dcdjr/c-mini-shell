#include "shell.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_loop(void) {
    char *line = NULL;
    size_t len = 0;

    while (1) {
        printf("%s", "myshell> ");
        fflush(stdout);

        if (getline(&line, &len, stdin) == -1) {
            break;
        }
        
        char** argv = parse_args(line);

        if (!argv) continue;

        pid_t pid = fork();

        if (pid == 0) {
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }

        free_args(argv);
    }

    free(line);
}

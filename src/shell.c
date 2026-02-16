#include "shell.h"
#include "parser.h"
#include "builtins.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void shell_loop(void) {
    char *line = NULL;
    size_t len = 0;

    signal(SIGINT, SIG_IGN);

    while (1) {
        printf("%s", "myshell> ");
        fflush(stdout);

        if (getline(&line, &len, stdin) == -1) {
            break;
        }
        
        char** argv = parse_args(line);
        if (!argv) continue;

        if (handle_builtin(argv)) {
            free_args(argv);
            continue;
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            free_args(argv);
            exit(1);
        }

        if (pid == 0) {
            signal(SIGINT, SIG_DFL);
            execvp(argv[0], argv);
            perror("execvp");
            _exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }

        free_args(argv);
    }

    free(line);
}

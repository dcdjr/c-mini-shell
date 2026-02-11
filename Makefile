CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -Iinclude -D_GNU_SOURCE
SRC = src/main.c src/shell.c src/parser.c src/builtins.c
OBJ = $(SRC:.c=.o)

myshell: $(OBJ)
	$(CC) $(CFLAGS) -o myshell $(OBJ)

clean:
	rm -f $(OBJ) myshell

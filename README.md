# Minimal Unix Shell (C)

A small Unix-like shell written in C using POSIX APIs.

The goal of this project was to understand core shell mechanics rather than build a feature-complete shell.

## Features

- Executing external programs with `fork` and `execvp`
- Built-in commands: `cd` and `exit`
- Command parsing into `argv`
- Correct parent/child process behavior
- Basic signal handling for `SIGINT`
- Modular code split across parsing, built-ins, and shell control flow
- Makefile-based build

## Non-Features

This shell intentionally does not support:

- Pipes (`|`)
- I/O redirection (`>`, `<`)
- Background jobs (`&`)
- Job control (`fg`, `bg`)
- Advanced environment manipulation

## Build and Run

```bash
make
./myshell
```

## Why This Project Matters

This project demonstrates practical understanding of:

- Unix process creation
- `fork` / `exec` execution flow
- Built-ins versus external commands
- Signal behavior in interactive programs
- Manual parsing and memory management in C

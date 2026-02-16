# Minimal Unix Shell (C)

This project is a small Unix-like shell written in C using POSIX APIs.  
The goal was to understand core shell mechanics rather than build a feature-complete shell.

The shell supports:
- Executing external programs using `fork` and `execvp`
- Built-in commands: `cd` and `exit`
- Proper argument parsing and memory management
- Signal handling so Ctrl-C terminates the running command without killing the shell

The code is split into separate modules for parsing, built-ins, and shell control flow, and is built using a Makefile.

## Features
- Command parsing into `argv`
- Process creation and execution
- Built-ins executed in the shell process
- Correct parent/child process behavior
- Basic signal handling (`SIGINT`)

## Non-features
This shell intentionally does not support:
- Pipes (`|`)
- I/O redirection (`>`, `<`)
- Background jobs (`&`)
- Job control (`fg`, `bg`)
- Environment manipulation beyond `cd`

## Build and Run

```sh
make
./myshell

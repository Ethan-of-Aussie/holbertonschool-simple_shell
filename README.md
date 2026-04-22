# Holberton-Simple-Shell

## Collaboration by Ethan and Sijin

## Description
This is an implementation of a simple shell environment written in C
The shell mimics the environment of standard shell "sh", with the goal of having the exact same output and error output as "sh"

## Requirements
* GCC compiler
* Ubuntu 22.04 (Holberton based sandbox)
* C standard -> gnu89

## Features
* Executes commands found in system PATH
* Supports the following builtin commands:
    * exit
    * env
* Handles command parsing and tokenization
* "Ctrl+d" to exit the shell (EOF)
* "Ctrl+c" to interrupt current process
* Forks child processes to execute external commands. Does not run commands when fork is not called
* Displays appropriate error messages
* Handles the following edge cases:
    * Empty PATH
    * Command not found (127)
    * Permisssion denied (126)

## Compilation
* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## How it Works
* After execution, shell awaits user input
* After input, the shell reads the input
* Input is then tokenized into arguments
* Builtin commands are checked
* Case when command is not builtin:
    * Shell resolves command path
    * Forks a child process
    * Executes commands using "execve"
* Parent process waits for completion of child process

## Memory Management
* Dynamically allocated mermory is freed without issues
* Tested using Valgrind to ensure no leaks

## Error Handling
* Command not found -> exit status 127
* Permission denied -> exit status 126

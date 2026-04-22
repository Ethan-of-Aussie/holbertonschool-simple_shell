.TH HSH 1 "April 2026" "Holberton Simple Shell" "User Commands"

.SH NAME
hsh \- simple UNIX command interpreter

.SH SYNOPSIS
.B hsh

.SH DESCRIPTION
.B hsh
is a simple UNIX command-line interpreter written in C
It reads commands from standard input, parses them, and executes them

The shell supports both interactive and non-interactive modes

.SH FEATURES
- Executes commands using PATH
- Built-in commands: exit, env
- Handles errors such as command not found, permission denied
- Supports EOF (Ctrl+D) to exit

.SH BUILTINS
.TP
.B exit
Exit the shell

.TP
.B env
Print the current environment

.SH USAGE
Interactive mode:
.PP
$ ./hsh

.PP
Non-interactive mode:
.PP
echo "ls -l" | ./hsh

.SH RETURN VALUE
The shell returns:
.TP
127 if command is not found
.TP
126 if permission is denied
.TP
0 on success

.SH ENVIRONMENT
The following environment variable is used:
.TP
.B PATH
Used to locate executable commands.

.SH EXAMPLES
.PP
$ ./hsh
.PP
$ ls
.PP
$ /bin/ls
.PP
$ exit

.SH AUTHORS
Ethan Hill
Sijin Singh

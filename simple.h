#ifndef SIMPLE_H
#define SIMPLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_INPUT 1024
#define MAX_LINE_SIZE 1024
void shell_loop(char** env);
char** parse_input(char* input);
void execute_command(char **args, char **env);
int _builtin(char **args, char **env);
char *_path(char *cmd);
#endif

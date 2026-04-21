#ifndef SIMPLE_H
#define SIMPLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#define MAX_INPUT 1024
#define MAX_LINE_SIZE 1024
int shell_loop(char **env);
char **parse_input(char *input);
int execute_command(char **args, char **env, int line);
int _builtin(char **args, char **env);
char *_path(char *cmd, char **env);
void malloc_error(void);
void free_tok(char **toks);
#endif

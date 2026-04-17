#ifndef SIMPLE_H
#define SIMPLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_INPUT 1024
void shell_loop(char** env);
char** parse_input(char* input);
int fork_main(void);
int wait_main(void);
int exec_main(void);
int error();
void execute_command(char **args, char **env);
char *_path(char *cmd);
#endif

#ifndef SIMPLE_H
#define SIMPLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_INPUT 1024
void shell_loop(char** env);
char** parse_input(char* input);
#endif

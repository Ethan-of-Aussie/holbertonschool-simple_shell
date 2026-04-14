#include "simple.h"
// prompt user, loop till user input, cmd ends wit newline
// prompt displays everytime after execution
// cmd lines simple
//cmd lines made of one word
// if no executable found print error message
// handle EOF
//execve pass environ to it
void shell_loop(char** env)
{
	char* input = NULL;
	size_t input_size = 0;

	char** args;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		if (getline(&input, &input_size, stdin) == -1)
	{
	      printf("\n");
	      break;
	}
	printf("./shell: %s", input);
	}
free(input);
}
int main (int ac, char** av, char** env)
{
	(void)ac;
	(void)av;

	shell_loop(env);
}

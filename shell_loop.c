#include "simple.h"
/**
 *shell_loop - Runs the main loof of the shell
 *@env: The environment
 *Return: The exit status of the last command
 */
int shell_loop(char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	char **args;
	int line = 0, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		fflush(stdout);
		if (getline(&input, &input_size, stdin) == -1)
			break;
		line++;

		args = parse_input(input);
		if (!args || !args[0])
		{
			if (args)
				free_tok(args);
			if (!isatty(STDIN_FILENO))
				continue;
			continue;
		}
		if (_builtin(args, env))
		{
			free_tok(args);
			break;
		}

		status = execute_command(args, env, line);

		free_tok(args);
		}
free(input);
return (status);
}

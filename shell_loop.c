#include "simple.h"
/**
 *shell_loop - Runs the main loof of the shell
 *@env: The environment
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
		{
			if (!isatty(STDIN_FILENO))
				break;
		break;
		}
		line++;

		args = parse_input(input);
		if (!args || !args[0])
		{
			free_tok(args);
			continue;
		}
		if (_builtin(args, env))
		{
			free_tok(args);
			continue;
		}

		status = execute_command(args, env, line);

		free_tok(args);
		}
free(input);
return (status);
}

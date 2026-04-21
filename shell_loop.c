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
	int i;
	int line = 0, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		fflush(stdout);
		if (getline(&input, &input_size, stdin) == -1)
		{
			free(input);
			return (status);
		}

		line++;

		args = parse_input(input);
		if (!args || !args[0])
		{
			// if (args)
			// 	free(args);
			free_tok(args);
			continue;
		}
		if (_builtin(args, env))
		{
			// free(input);
			// free_tok(args);
			// exit(status);
			free_tok(args);
			continue;
		}

		status = execute_command(args, env, line);

		free_tok(args);

// 		for (i = 0; args[i]; i++)
// 			free(args[i]);
// 		free(args);
// 	}
// free(input);
// return (status);
}

#include "simple.h"
/**
 *execute_command - Command execution through the shell
 *@args: Arguments representing pathing and commands
 *@env: The environment
 */
void execute_command(char **args, char **env)
{
	pid_t pid;
	char *pathing;

	if (!args || !args[0])
	{
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		pathing = _path(args[0]);
		if (pathing)
		{
			execve(pathing, args, env);
			free(pathing);
		}
		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(127);
	}
	else
	{
		wait(NULL);
	}
}

#include "simple.h"
/**
 * run_child - Forks and executes a command in a child process
 * @pathing: Full resolved path to the executable
 * @args: Argument vector for the command
 * @env: The environment
 * @line: Line counter for error messages
 *
 * Return: The exit status of the executed command, or 1 on failure
 */
int run_child(char *pathing, char **args, char **env, int line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(pathing, args, env);

		if (errno == EACCES)
		{
			fprintf(stderr, "./hsh: %d: %s: Permission denied\n", line, args[0]);
			_exit(126);
		}

		fprintf(stderr, "./hsh: %d: %s: not found\n", line,  args[0]);
		_exit(127);
	}
	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
return (1);
}

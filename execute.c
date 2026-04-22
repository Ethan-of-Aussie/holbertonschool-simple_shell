#include "simple.h"
/**
 *execute_command - Command execution through the shell
 *@args: Arguments representing pathing and commands
 *@env: The environment
 *@line: The counter for the command error
 *
 *Return: The error to shell_loop, or continue the loop
 */
int execute_command(char **args, char **env, int line)
{
	char *pathing = NULL;
	int status;

	if (!args || !args[0])
		return (0);
	if (_builtin(args, env))
		return (0);
	if (strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) != 0)
		{
			if (errno == EACCES)
			fprintf(stderr, "./hsh: %d: %s: Permission denied\n", line, args[0]);
			else
			{
			fprintf(stderr, "./hsh: %d: %s: not found\n", line,  args[0]);
			return (127);
			}
		}
	pathing = args[0];
	}
	else
	{
		pathing = res_path(args[0], env, line);
		if (!pathing)
			return (127);
	}
	status = run_child(pathing, args, env, line);

	if (pathing != args[0])
		free(pathing);
return (status);
}

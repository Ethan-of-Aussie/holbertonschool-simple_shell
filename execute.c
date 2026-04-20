#include "simple.h"
/**
 *execute_command - Command execution through the shell
 *@args: Arguments representing pathing and commands
 *@env: The environment
 */
int execute_command(char **args, char **env, int line)
{
	pid_t pid;
	char *pathing;
	int status;

	if (!args || !args[0])
	{
		return (0);
	}
	if (_builtin(args, env))
	  return (0);
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (args[0][0] == '/' || args [0][0] == '.')
		{
			execve(args[0], args, env);
			fprintf(stderr, "./hsh: %d: %s: not found\n", line, args[0]);
			exit(127);
		}
		

		pathing = _path(args[0]);
		if (pathing)
		{
			/**fprintf(stderr, "./hsh: %d: %s: not found\n", line, args[0]);
			* exit(127);
			*/

			execve(pathing, args, env);
			free(pathing);
		}

		 if (errno == EACCES)
        	{
            		fprintf(stderr, "./hsh: %d: %s: Permission denied\n", line, args[0]);
            		exit(126);
        	}
		
		fprintf(stderr, "./hsh: %d: %s: not found\n", line,  args[0]);
		exit(127);
	}

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}

		return (1);
}

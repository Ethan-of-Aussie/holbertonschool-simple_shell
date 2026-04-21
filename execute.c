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
		return (0);
	if (_builtin(args, env))
	  {
		return (0);
	  }
		if (args[0][0] == '/' || args [0][0] == '.')
		{
		  if (access(args[0], X_OK) != 0)
		    {
			if (errno == EACCES)
			fprintf(stderr, "./hsh: %d: %s: Permission denied\n", line, args[0]);
                        else
			fprintf(stderr, "./hsh: %d: %s: not found\n", line,  args[0]);
                return (127);
		}
		pathing = args[0];
		}
		else
		  {
		    pathing = _path(args[0], env);
		if (!pathing)
		  {
		fprintf(stderr, "./hsh: %d: %s: not found\n", line,  args[0]);
		return (127);
		}
		}
		pid = fork();
		if (pid == -1)
		{
		perror("fork");
		if (pathing != args[0])
			free(pathing);
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
		if (pathing != args[0])
		  free(pathing);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (1);
}

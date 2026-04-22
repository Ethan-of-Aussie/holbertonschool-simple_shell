#include "simple.h"
/**
 *res_path - Resolves the pathing of the command
 *@cmd: The executable command
 *@env: The environment
 *@line: The counter for command error
 *Return: The resolved path or NULL on error
 */
char *res_path(char *cmd, char **env, int line)
{
	char *pathing = NULL;
	char *path_env = NULL;
	int i;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}
	if (!path_env || path_env[0] == '\0')
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", line, cmd);
		return (NULL);
	}
	pathing = _path(cmd, env);
	if (!pathing)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", line,  cmd);
		return (NULL);
	}
return (pathing);
}

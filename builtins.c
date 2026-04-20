#include "simple.h"
/**
 *_builtin - Checks if the string is a built-in executable
 *@args: Representing commands
 *@env: The environment
 *Return: 0 if not found or 1 if found and to continue the shell_loop
 */
int _builtin(char **args, char **env)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
		return(1);

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; env[i]; i++)
			printf("%s\n", env[i]);
		return (1);
	}
return (0);
}

#include "simple.h"

int _builtin(char **args, char **env)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; env[i]; i++)
			printf("%s\n", env[i]);
		return (1);
	}
return (0);
}

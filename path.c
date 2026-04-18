#include "simple.h"
/**
getenv()
stat()
access()
strdup()

 */
char *_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy = strdup(path);

	if (!path)
		return (NULL);
	if (!copy)
		return (NULL);

	if (!cmd)
	{
		return (NULL);
	}

	if (access(cmd, X_OK) == 0)
	{
		return (cmd);
	}

	return (NULL);
}

#include "simple.h"

char *_path(char *cmd)
{
/**Previous code might be used for next task	
 * char *path = getenv("PATH");
 * char *copy = strdup(path);
 * access(copy, X_OK);
 * return (NULL);
 */
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

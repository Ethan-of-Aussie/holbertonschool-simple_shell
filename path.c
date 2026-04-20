#include "simple.h"
/**
 */
char *_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy = strdup(path);
	char *dir = strtok(copy, ":");
	char full[MAX_LINE_SIZE];

	if (!path)
		return (NULL);
	if (!copy)
		return (NULL);
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
	{
		free(copy);
		return (strdup(cmd));
	}
	while (dir)
	{
		snprintf(full, sizeof(full), "%s/%s", dir, cmd);
	if (access(full, X_OK) == 0)
		{
			free(copy);
			return (strdup(full));
		}
	dir = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}

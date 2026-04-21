#include "simple.h"

/**
 *_path - Path Resolution, resolves commands to the full executable path
 *@cmd: The command entered by the user
 *
 *Return: Either a pointer to a new allocated string holding the resolved
 *full path, or NULL if the command cannot be resolved
 */
char *_path(char *cmd, char **env)
{
	char *path = NULL;
	char *copy, *dir;
	char full[MAX_LINE_SIZE];
	int i;

	if (!cmd)
		return (NULL);
	
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
	}
	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));
	if (!path)
		return (NULL);
	copy = strdup(path);
	if (!copy)
		return (NULL);
	dir = strtok(copy, ":");
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

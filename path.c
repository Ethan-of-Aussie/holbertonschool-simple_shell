#include "simple.h"

char *_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy = strdup(path);
	
	access(copy, X_OK);

	return (NULL);
}

#include "simple.h"

char *_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy = strdup(path);
	
	access(X_OK, copy);

	stat();

	return;
}

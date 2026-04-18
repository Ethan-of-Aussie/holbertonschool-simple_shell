#include "simple.h"
/**
getenv()
stat()
access()
strdup()
use snprintf() not sprintf()
 */
char *_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy = strdup(path);
	char *dir = strtok(copy, ":");
	char full[MAX_LINE_SIZE];
	struct stat buffer; /** from #include <sys/stat.h> */

	if (!path)
		return (NULL);
	if (!copy)
		return (NULL);
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));

	while (dir)
	  {
	    
	  }
	free(copy);
	return (NULL);
}

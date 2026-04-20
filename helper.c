#include "simple.h"
/**
 * malloc_error - Handles memory allocation failure
 * Description: Prints error message than exits the program
 */
void malloc_error(void)
{
	perror("Malloc");
	exit(EXIT_FAILURE);
}
/**
 *free_tok - Free tokens
 *Description: Used to free tokenizations
 */
void free_tok(char **toks)
{
	int i;

	if (!toks)
	return;

	for (i = 0; toks[i]; i++)
		free(toks[i]);
	free(toks);
}

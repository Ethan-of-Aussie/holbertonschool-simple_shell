#include "simple.h"
/**
 *helper functions to make things more simple
 */

/**
 * malloc_error - Handles memory allocation failure
 */
void malloc_error(void)
{
	perror("Malloc");
	exit(EXIT_FAILURE);
}

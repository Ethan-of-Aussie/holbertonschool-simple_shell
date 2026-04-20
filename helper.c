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

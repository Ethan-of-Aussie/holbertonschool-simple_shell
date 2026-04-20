#include "simple.h"
/** 
 * main - Passes the environment to shell_loop
 *@ac: Argument count
 *@av: Argumetn variables
 *@env: The environment
 */
int main (int ac, char** av, char** env)
{
	(void)ac;
	(void)av;

	shell_loop(env);

	return (0);
}

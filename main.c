#include "simple.h"
/** 
 * prompt user, loop till user input, cmd ends wit newline
 * prompt displays everytime after execution
 * cmd lines simple
 * cmd lines made of one word
 * if no executable found print error message
 * handle EOF
 * execve pass environ to it
 */

int main (int ac, char** av, char** env)
{
	(void)ac;
	(void)av;

	shell_loop(env);

	return (0);
}

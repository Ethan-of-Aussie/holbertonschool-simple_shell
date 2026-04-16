#include "simple.h"

int main (int ac, char** av, char** env)
{
	(void)ac;
	(void)av;

	shell_loop(env);

	return (0);
}

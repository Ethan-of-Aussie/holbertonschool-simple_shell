#include "simple.h"
/**
 *main - Entry of the shell
 *@ac: Argument count
 *@av: Argumetn vector
 *@env: The environment
 *Return: always 0
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	shell_loop(env)
	return (0);
}

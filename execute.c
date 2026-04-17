#include "simple.h"

void execute_command(char **args, char **env)
{
    pid_t pid;
    
    if (!args || !args[0])
    {
	    return;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        if (execve(args[0], args, env) == -1)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(127);
	}
    }
    else
    {
        wait(NULL);
    }
}

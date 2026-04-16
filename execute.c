#include "simple.h"

void execute_command(char **args, char **env)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        execve(args[0], args, env);
        perror("./shell");
        exit(1);
    }
    else
    {
        wait(NULL);
    }
}

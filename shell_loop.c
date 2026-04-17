#include "simple.h"

void shell_loop(char** env)
{
        char* input = NULL;
        size_t input_size = 0;
	char **args;
	int i;
        
	while (1)
        {
                printf("#cisfun$ ");
                fflush(stdout);
                
		if (getline(&input, &input_size, stdin) == -1)
		{
			printf("\n");
			break;
		}
		
		args = parse_input(input);
		if (!args || !args[0])
		{
			continue;
		}

		execute_command(args,env);

		for (i = 0; args[i]; i++)
		{
			free(args[i]);
		}

		free(args);
	}

free(input);
}

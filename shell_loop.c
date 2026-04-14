#include "simple.h"

void shell_loop(char** env)
{
        char* input = NULL;
        size_t input_size = 0;

        char** args;
        while (1)
        {
                printf("#cisfun$ ");
                fflush(stdout);
                if (getline(&input, &input_size, stdin) == -1)
        {
              printf("\n");
              break;
        }
        printf("./shell: %s", input);
        }
free(input);
}

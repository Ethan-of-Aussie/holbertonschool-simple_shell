#include "simple.h"

/**
* main - execve example
*
* Return: 0
*/

int main(void)
{
  char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

  printf("Before execve\n");

  if (execve(argv[0], atgv, NULL == -1)
  {
    perror("Error:");
  }

  printf("After execve\n");

  return (0);
}

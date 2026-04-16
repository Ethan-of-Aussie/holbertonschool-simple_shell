#include "simple.h"

int fenv(int ac , char *av[], char *env)
{
  int i = 0;
  while (env[i])
    {
      printf ("%s\n", env[i]);
      i++;
    }

}

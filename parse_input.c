#include "simple.h"

char** parse_input(char* input)
{
	size_t buf_size = MAX_INPUT;
	char** tokens = malloc(buf_size * sizeof(char*));
	char* token = NULL;
	size_t position = 0;
	size_t token_length = 0;
	size_t i, j;

	if (!tokens)
	{
	perror("Malloc");
	exit(EXIT_FAILURE);
	}

	for (i = 0; input[i]; i++)
	{
		while (input[i] == ' ')
			i++;

		if (!input[i])
			break;

		token = &input[i];
	while (input[i] && input[i] != ' ')
	{
		token_length++;
		i++;
	}

	tokens[position] = malloc((token_length + 1) * sizeof(char));
	if (!tokens[position])
	{
		perror("Malloc");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < token_length; j++)
	{
		tokens[position][j] = token[j];
	}
	tokens[position][token_length] = '\0';
	position++;
	token_length = 0;
}
tokens[position] = NULL;
return (tokens);
}

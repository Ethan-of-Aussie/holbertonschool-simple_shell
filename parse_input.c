#include "simple.h"
/**
 *parse_input - Splits a line of input into array of tokens
 *@input: The input string entered by the user
 *Return: A NULL-terminated array of strings holding the tokens. NULL on fail
 */
char **parse_input(char *input)
{
	size_t position = 0, token_length = 0, buf_size = MAX_INPUT, i, j;
	char **tokens = malloc(buf_size * sizeof(char *));
	char *token;

	if (!tokens)
		malloc_error();
	input[strcspn(input, "\n")] = '\0';
	for (i = 0; input[i]; )
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
			malloc_error();
		for (j = 0; j < token_length; j++)
			tokens[position][j] = token[j];
	tokens[position][token_length] = '\0';
	position++;
	token_length = 0;
	}
tokens[position] = NULL;
return (tokens);
}

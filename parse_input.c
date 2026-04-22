#include "simple.h"
/**
 *parse_input - Splits a line of input into array of tokens
 *@input: The input string entered by the user
 *Return: A NULL-terminated array of strings holding the tokens. NULL on fail
 */
char **parse_input(char *input)
{
	size_t position = 0, buf_size = MAX_INPUT;
	char **tokens = malloc(buf_size * sizeof(char *));
	char *token;

	if (!tokens)
		malloc_error();
	input[strcspn(input, "\n")] = '\0';
		while (*input == ' ' || *input == '\t')
			input++;
		if (*input == '\0')
		{
			tokens[0] = NULL;
			return (tokens);
		}
		token = strtok(input, " \t");

		while (token)
		{
			tokens[position] = token;
			position++;

			token = strtok(NULL, " \t");
		}
tokens[position] = NULL;
return (tokens);
}

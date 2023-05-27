#include "main.h"

/**
 * tokenizer_path - tokize path into tokens
 * @input: path tokenize
 * Return: return array of tokens
 */
char **tokenizer_path(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, DELIM_P);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM_P);
	}
	tokens[position] = NULL;
	return (tokens);
}

#include "main.h"

/**
 * builtin_unsetenv - delete enviroment variable
 * @args: array of tokens
 * @input_stdin: Input from stdin
 * @exit_status: exit status
 * Return: return 1 if scuess otherwise 0
 */
int builtin_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	if (n_tokens == 2)
		unsetenv(args[1]);
	else if (n_tokens != 2)
		fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");

	return (1);
}

#include "main.h"

/**
 * builtin_setenv - change or add and environment
 * @args: array of tokens
 * @input_stdin: inputfrom stdin
 * @exit_status: exit
 * Return: Return 1 if success or 0 if failed
 */
int builtin_setenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	if (n_tokens == 3)
		setenv(args[1], args[2], 1);

	else if (n_tokens != 3)
		fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");
	return (1);
}

#include "main.h"

/**
 * builtin_exit - exit process
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: exit success
 */
int builtin_exit(char **args, char *input_stdin, int *exit_status)
{

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
	}
	if (args[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (0);
	}
	free(args);
	free(input_stdin);
	exit(0);
}

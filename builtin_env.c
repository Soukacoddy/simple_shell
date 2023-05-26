#include "main.h"

/**
 * builtin_env - print enviromental
 * @args: arguments used
 * @input_stdin: input of standard input
 * @exit_status: exit status
 * Return: return 1
 */
int builtin_env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;


	if (environ[i] == NULL)
	{
		printf("%s", "The built in env is empty");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}

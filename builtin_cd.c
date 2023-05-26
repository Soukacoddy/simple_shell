#include "main.h"

/**
 * builtin_cd - Change directory using cd
 * @args: tokens array
 * @input_stdin: input from standard input
 * @exit_status: exit status
 * Return: return sucess
 */
int builtin_cd(char **args, char *input_stdin, int *exit_status)
{
	int stat;
	char str[128];

	getcwd(str, sizeof(str));

	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
		stat = chdir(getenv("HOME"));
	else if (strcmp(args[1], "-") == 0)
		stat = chdir(getenv("OLDPWD"));
	else if (strcmp(args[1], "~") == 0)
		stat = chdir(getenv("HOME"));
	else
		stat = chdir(args[1]);

	if (stat == -1)
		perror("cd had an error");

	setenv("OLDPWD", str, 1);
	setenv("PWD", getcwd(str, sizeof(str)), 1);
	return (1);
}

#include "main.h"

/**
 * hsh_execute_builtins - excute with builtin
 * @args: arguments
 * @input_stdin: String from input
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: return 1 if sucess or 0 if not
 */
int shell_execute_builtins(char **args, char *input_stdin,
			 char **argv, int *exit_status, int count_command)
{
	int i = 0;

	choose_builtins_t options[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd},
		{NULL, NULL}
	};

	while (options[i].name_builtin)
	{
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	return (builtin_execute(args, argv, exit_status, count_command));
}

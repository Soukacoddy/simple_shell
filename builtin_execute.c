#include "main.h"

/**
 * builtin_execute - execute in child process
 * @arguments: String of arguments
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: return 1
 */
int builtin_execute(char **arguments, char **argv, 
		int *exit_status, int count_command)
{
	pid_t pid_used;
	int status;
	char *new_arguments;

	new_arguments = validate_input(arguments, argv, count_command);
	if (strcmp(new_arguments, "Fail access") == 0)
		return (1);

	pid_used = fork();
	if (pid_used == 0)
	{
		if (execve(new_arguments, arguments, environ) == -1)
		{
			perror("execve fail");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid_used < 0)
	{
		perror("Error forking");
		free(new_arguments);
		return (1);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			*exit_status = WEXITSTATUS(status);
		if (arguments[0][0] != '/' && arguments[0][0] != '.')
			free(new_arguments);
		return (1);
	}
	return (1);
}

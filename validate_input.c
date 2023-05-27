#include "main.h"

/**
 * execute_child_process - Executes the child process
 * @new_arguments: Arguments for the child process
 * @arguments: String of arguments
 * @exit_status: Exit status
 */
void execute_child_process(char *new_arguments,
	char **arguments, int *exit_status)
{
	if (execve(new_arguments, arguments, environ) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_fork_error - Handles the error when forking
 * @new_arguments: Arguments for the child process
 */
void handle_fork_error(char *new_arguments)
{
	perror("Error forking");
	free(new_arguments);
}

/**
 * wait_for_child_process - Waits for the child process to finish
 * @status: Status of the child process
 * @exit_status: Exit status
 * @arguments: String of arguments
 * @new_arguments: Arguments for the child process
 */
void wait_for_child_process(int *status, int *exit_status,
	char **arguments, char *new_arguments)
{
	waitpid(-1, status, 0);
	if (WIFEXITED(*status))
		*exit_status = WEXITSTATUS(*status);
	if (arguments[0][0] != '/' && arguments[0][0] != '.')
		free(new_arguments);
}

/**
 * builtin_execute - Execute in child process
 * @count_command: Count the command
 * @arguments: String of arguments
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: 1
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
		execute_child_process(new_arguments, arguments, exit_status);
	else if (pid_used < 0)
		handle_fork_error(new_arguments);
	else
		wait_for_child_process(&status, exit_status, arguments, new_arguments);

	return (1);
}


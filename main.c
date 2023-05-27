#include "main.h"

/**
 * main - simple shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: return 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char **arguments = NULL;
	char *input_stdin = NULL;
	int stat_return = 1, exit_stat = 0;
	int count_commands = 1;
	size_t size = 0;
	ssize_t n = 0;

	while (stat_return && n != EOF)
	{
		size = 0;
		stat_return = isatty(STDIN_FILENO);
		if (stat_return)
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, sigintH);
		n = getline(&input_stdin, &size, stdin);
		if (n == -1)
		{
			free(input_stdin);
			break;
		}
		if (validate_spaces(input_stdin))
		{
			free(input_stdin);
			continue;
		}
		arguments = hsh_tokenizer(input_stdin);
		if (*arguments[0] == '\0')
			continue;
		stat_return = shell_execute_builtins(arguments, input_stdin,
				argv, &exit_stat, count_commands);
		free(input_stdin);
		free(arguments);
		count_commands++;
	}
	return (0);
}

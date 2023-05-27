#include "main.h"

/**
 * print_st_error - print error string
 * @argv: first string
 * @argment: second string
 * @count: number of command typed
 * Return: return string
 */

char *print_st_error(char *argv, char *argment, int count)
{
	print_st(argv);
	print_st(": ");
	print_intiger(count);
	print_st(": ");
	print_st(argment);
	print_st(": not found\n");
	return ("Fail access");
}

/**
 * validate_input - validate input
 * @arguments: String of tokens
 * @argv: arguments from input
 * @count: number of argment typed
 * Return: return array of the tokenized PATH
 **/
char *validate_input(char **arguments, char **argv, int count)
{
	char *new_arguments, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (arguments[0][0] == '/' || arguments[0][0] == '.')
	{
		new_arguments = arguments[0];
		if ((access(new_arguments, F_OK) == -1))
			return (print_st_error(argv[0], arguments[0], count));
	}
	else
	{
		strcpy(holder_env, getenv("PATH"));
		tokens_path = tokenizer_path(holder_env);
		while (tokens_path[i])
		{
			first = str_concat(slash_argument, arguments[0]);
			new_arguments = str_concat(tokens_path[i], first);
			if ((access(new_arguments, F_OK) == -1))
			{
				free(new_arguments);
				free(first);
			}
			else
			{
				free(tokens_path);
				free(first);
				return (new_arguments);
			}
			i++;
		}
		free(tokens_path);
		return (print_st_error(argv[0], arguments[0], count));
	}
	return (new_arguments);
}

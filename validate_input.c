#include "main.h"

/**
 * validate_input - validate input
 * @arguments: String of tokens
 * @argv: arguments from input
 * Return: return array of the tokenized PATH
 **/
char *validate_input(char **arguments, char **argv __attribute__((unused)), int count_command)
{
	char *new_arguments, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (arguments[0][0] == '/' || arguments[0][0] == '.')
	{
		new_arguments = arguments[0];
		if ((access(new_arguments, F_OK) == -1))
		{
				print_st(argv[0]);
				print_st(": ");
				print_intiger(count_command);
				print_st(": ");
				print_st(arguments[0]);
				print_st(": not found\n");
			return ("Fail access");
		}
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
		print_st(argv[0]);
		print_st(": ");
		print_intiger(count_command);
		print_st(": ");
		print_st(arguments[0]);
		print_st(": not found\n");
		return ("Fail access");
	}
	return (new_arguments);
}

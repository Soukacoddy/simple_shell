#include "main.h"

/**
 * validate_spaces - validate spaces, tabs and line breaks
 * @input: string from input
 * Return: 0 if not find spaces, tabs or line break
 */
int validate_spaces(char *input)
{
	int i = 0, flag = 1, len = 0;

	len = strlen(input);

	while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		i++;

	if (i != len)
		flag = 0;
	return (flag);
}

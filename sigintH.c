#include "main.h"

/**
 * sigintH - Handles(CTRL + C)
 * @signum: Signal number caught by signal, 2 for SIGINIT
 * Return: void
 **/
void sigintH(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n$ ", 3);
	}
}
/**
* print_inger: length of string
* @s: string arg
*/

void print_intiger(int i)
{
	char c;

	if(i != 0) {
		print_intiger(i / 10);
		c = (i % 10) + '0';
		write(1, &c, 1);
	}
}

/**
* print_st: length of string
* @s: string arg
*/

void print_st(char *s)
{
	char c;
	int i = 0;
	while (s[i])
	{
		c = s[i];
		write(1, &c, 1);
		i++;
	}
}

/**
* _strlen: length of string
* @s: string arg
* return: return length
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

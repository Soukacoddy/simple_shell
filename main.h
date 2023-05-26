#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define BUFSIZE 64
#define DELIM_I " \t\n"
#define DELIM_P ":"

/**
 * struct choose_builtin - Builtin commands struct
 * @name_builtin: Name of builtin command
 * @func_builtin: Pointer to builtin command functions
 */
typedef struct choose_builtin
{
	char *name_builtin;
	int (*func_builtin)(char **, char *, int *);

} choose_builtins_t;

extern char **environ;

void print_st(char *s);
int _strlen(char *s);
void print_intiger(int i);

char **hsh_tokenizer(char *input);
char **tokenizer_path(char *input);

char *validate_input(char **arguments, char **argv, int count_command);
int validate_spaces(char *input);

int builtin_execute(char **arguments, char **argv, int *exit_status, int count_command);
int shell_execute_builtins(char **args, char *input_stdin,
			 char **argv, int *exit_status, int count_command);

int builtin_cd(char **args, char *input_stdin, int *exit_status);
int builtin_setenv(char **args,  char *input_stdin, int *exit_status);
int builtin_unsetenv(char **args,  char *input_stdin, int *exit_status);
int builtin_env(char **args, char *input_stdin, int *exit_status);
int builtin_exit(char **args, char *input_stdin, int *exit_status);

void sigintH(int signum);
char *str_concat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif

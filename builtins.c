#include "shell.h"

/**
  * run_command - Gets the functions for builtin command
  * @cmd: buitin command arg
  * Return: pointer to function
  */
int (*run_command(char *cmd))(char **tokens, char *line)
{

	commands allcommand[] = {
		 {"cd", handle_chdir},
		 {"help", handle_help},
		 {"exit", handle_exit},
		 {"env", print_env},
		 {NULL, NULL}
	 };
	int i;

	for (i = 0; allcommand[i].cmd; i++)
	{
		if (strcmp(allcommand[i].cmd, cmd) == 0)
		{
			return (allcommand[i].func);
		}
	}
	return (NULL);
}


/*COMMAND FUNCTIONS */


/**
  * handle_chdir - change directory
  * @tokens: pointer to array of cmd line
  * Return: interger
  */
int handle_chdir(char **tokens, char *line)
{
	char *home;

	if (tokens[1])
	{
		chdir(tokens[1]);
		frees_tokens(tokens);
		free(line);
		exit (0);
	} else
	{
		home = _getenv("HOME");
		chdir(home);
		frees_tokens(tokens);
		free(line);
	}
	frees_tokens(tokens);
	free(line);
	exit (0);
}
/**
  * handle_help - print the help page
  * @tokens: pointer to array of cmd line
  * Return: 1
  */
int handle_help(char __attribute__((unused)) **tokens, char *line)
{
	_puts("\n***HSH HELP PAGE***\n");
	frees_tokens(tokens);
	free(line);
	exit (0);
}
/**
  * print_env - print environmental variables
  * @tokens: pointer to array of cmd line arguments
  * Return: 1
  */
int print_env(char __attribute__((unused)) **tokens, char *line)
{
	int i, j = 0;

	while (environ[j])
	{
		i = 0;
		while (environ[j][i])
		{
			_putchar(environ[j][i]);
			i++;
		}
		if (i != 0)
			_putchar('\n');
		j++;
	}
	frees_tokens(tokens);
	free(line);
	exit(0);
}
/**
  * handle_exit - handles exit out of the command line
  * @tokens: pointer to array of cmd arguments
  * Return: integers
  */
int handle_exit(char __attribute__((unused)) **tokens, char *line)
{
	int status = 0;

	if (tokens[1] == NULL || (!_strcmp(tokens[1], "0")))
	{
		frees_tokens(tokens);
		exit(0);
	}
	status = _atoi(tokens[1]); /* converts to integer */
	if (status != 0)
	{
		frees_tokens(tokens);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(tokens[1]);
		_puts("\n");
		exit(2);
	}

	frees_tokens(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}

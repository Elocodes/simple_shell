#include "shell.h"
/**
  * main - entry point to simple shell program"
  *
  * Return: 0 for success
  */
int main(void)
{
	char *cmd;
	char **tokens;
	char **envp = {NULL};

	while (1)
	{
		printf("$ ");

		cmd = read_line();

		tokens = get_token(cmd);

		execute(tokens);

		free(tokens);
		free(cmd);
	}
	return (0);
}

#include "shell.h"

/**
  * execute - execute the commands
  * @str: pointer to array of tokens
  * Return: 0 for success
  */
int execute(char **str)
{
	int status;
	char **envp = {NULL};
	pid_t pid;
	struct stat st;
	pid = fork();

	if (pid == 0)
	{
		if (stat(str[0], &st) == -1)
		{
			dprintf(2, "Error: File not executable\n");
			exit(99);
		}
		if (execve(str[0], str, envp) == -1)
		{
			dprintf(2, "Error executing\n");
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

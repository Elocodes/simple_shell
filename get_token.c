#include "shell.h"

int execute(char **str)
{
	int status;
	char *path;
	char **envstr = {NULL};
	pid_t pid;



	pid = fork();

	if (pid == 0)
	{
		if (execve(path, str, envstr) == -1)
		{
			dprintf(2, "Error executing\n");
		}
	}
	else
	{
		wait(&status);
	}


}
/**
  * get_token - get an array of the strings passed in the line
  */
char **get_token(char *line)
{

	char *tok;
	char *del = " ";
	char **tokens;
	int i = 0;

	if (line == NULL)
	{
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * 64);
	tok = strtok(line, del);
	while (tok != NULL)
	{
		tokens[i] = strdup(tok);
		i++;
		tok = strtok(NULL, del);
	}
	tokens[i] = tok;

	return (tokens);
}
/**
int main(int argc, char **argv)
{
	char **tok;
	if (argc != 2)
	{
		dprintf(2, "Error 1\n");
	}
	printf("%s\n", argv[1]);
	tok = get_token(argv[1], " ");

	printf("%s\n", tok[0]);
	return (0);
}*/

#include "shell.h"
/**
  * main - implement "ls -l /tmp"
  */
int main(int argc, char **argv)
{
	char **tokens;
	char *buff = NULL;
	size_t bufsize;

	int mode = 1;
	while (mode)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "$ ", 3);
		if (getline(&buff, &bufsize, stdin) == -1)
		{
			dprintf(STDERR_FILENO, "Error: reading line\n");
		}

		printf("TWO %s", buff);
		tokens = get_token(buff);
		execute(tokens);
	}

	return (0);
}

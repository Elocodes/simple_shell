#include "shell.h"

/**
  * main - Entry point to shell program
  *
  * Return: Always zero.
  */
int main(void)
{
	char *line = NULL, **tokens = NULL;
	int w_len = 0;
	int (*fptr)(char **tokens);
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		else
		{
			write(STDOUT_FILENO, "$ ", 2);
			exit(0);
		}
		line = read_line();
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		w_len = count_input(line);
		if (line[0] != '\n' && w_len > 0)
		{
			tokens = get_token(line, " \t");
			free(line);
			fptr = run_command(tokens[0]); /* runs and returns builtin func */
			if (!fptr) /* checks that its not a buitin command */
			{
				tokens[0] = find(tokens[0]);
				if (tokens[0] && access(tokens[0], X_OK) == 0)
					exec(tokens[0], tokens);
				else
					perror("./hsh");
			}
			else
				fptr(tokens);

			frees_tokens(tokens);
		}
	}

	return (0);
}

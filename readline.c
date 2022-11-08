#include "shell.h"
/**
  * read_line - reads users input
  * Return: pointer to the string entered by user
  */
char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int buflen;

	if (buflen = getline(&buf, &bufsize, stdin) == -1)
	{
		dprintf(2, "Error: reading from line\n");
		free(buf);
	}
	if (buf[buflen - 1] == '\n')
		buf[buflen - 1] = '\0';

	return (buf);
}

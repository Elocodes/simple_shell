#include "shell.h"

int linelen(char *str, char *del);
int countword(char *str, char *del);
/**
  * get_token - get an array of the strings passed in the line
  * @line: pointer to read line
  * @del: pointer to cdelimiter
  * Return: array of tokens
  */
char **get_token(char *line, char *del)
{
	char *tok = NULL;
	char *temp = NULL;
	char **tokens = NULL;
	int count = 0, i = 0;

	count = countword(line, del);
	tokens = malloc(sizeof(char *) * (count + 1));

	if (tokens == NULL)
		return (NULL);

	line = remove_new_line(line);
	temp = strdup(line);
	tok = strtok(line, del);
	while (tok)
	{
		tokens[i] = strdup(tok);
		tok = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	free(temp);
	return (tokens);
}
/**
  * linelen - counts the len of word in the read line
  * @str: pointer to the line
  * @del: pointer to delimiter
  * Return: num of chars
  */
int linelen(char *str, char *del)
{
	int len = 0, i = 0;

	while (str[i] && str[i] != *del)
	{
		len++;
		i++;
	}
	return (len);
}

/**
  * countword - counts number of words
  * @str: pointer to the line
  * @del: pointer to delimiter
  * Return: number of words
  */
int countword(char *str, char *del)
{
	int word = 0, i = 0, len = 0;

	for (i = 0; str[i]; i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (str[i] != *del)
		{
			word++;
			i += linelen(str + i, del);
		}
	}
	return (word);
}

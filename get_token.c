#include "shell.h"

int linelen(char *str, char *del);
int countword(char *str, char *del);
/**
  * get_token - get an array of the strings passed in the line
  * @line: pointer to the line to be tokenized
  * Return: pointer to array of tokens
  */
char **get_token(char *line)
{
	char *tok;
	char **tokens;
	char *del = " \n\t";
	int count = 0, i = 0;

	if (line == NULL)
	{
		exit(1);
	}

	count = countword(line, del);
	tokens = malloc(sizeof(char *) * (count + 1));

	tok = strtok(line, del);
	while (tok)
	{
		tokens[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	tokens[i] = tok;

	return (tokens);
}
/**
  * linelen - gets the length of character in a token
  * @str: line
  * @del: the delimiter
  * Returns: len of token
  */
int linelen(char *str, char *del)
{
	int len = 0, i =0;

	while (str[i] && str[i] != *del)
	{
		len++;
		i++;
	}
	return (len);
}
/**
  * countword - number of tokens, separated by delimiter
  * @str: line
  * @del: delimkiter
  * Return: Number of tokens
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

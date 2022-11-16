#include "shell.h"
/**
  * _getenv - gets the value of environment variable
  * @name: name of env variable
  * Return: value of the env variable
  */
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{			
			env_var = _strdup(environ[i]);			
			while (*env_var != '=')
				env_var++;

			++env_var;		
			return (env_var);		
		}
		i++;
	}
	return (NULL);
}

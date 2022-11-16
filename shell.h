#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/**
  * struct run_commands - struct of buitin command functions
  * @cmd: buitin command
  * @func: pointer to function
  */
typedef struct run_commands
{
	     char *cmd;
	     int (*func)(char **);
} commands;


extern char **environ;

char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int count_input(char *str);
int count_delims(char *, char *);
char *remove_new_line(char *);
void signal_handler(int);
int handle_help(char **);
int print_env(char **);
int handle_exit(char **);
int handle_chdir(char **);
char *read_line(void);
int (*run_command(char *))(char **);
void frees_get_env(char *env_path);
void frees_tokens(char **);
int exec(char *cname, char **opts);
char *_getenv(const char *);
char **get_token(char *, char *);
char *find(char *cname);

#endif

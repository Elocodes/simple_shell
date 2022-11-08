#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
/**
  * struct aliases - names of aliases available to my_sh cli
  */
typedef struct aliases {
	char *alias;
	char *real_name;
} alias;


typedef struct run_commands {
	char *cmd;
	void (*command) (char *);
} commands;

void run_command(char **);
void echoline(char *);
void exitprompt(char *);
void changedir(char *);
char *read_line(void);
int countword(char *, char *);
char **get_token(char *);
int execute(char **);

#endif

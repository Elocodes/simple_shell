#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
  * struct aliases - names of aliases available to my_sh cli
  */
typedef struct aliases {
	char *alias;
	char *real_name;
} alias;

char **get_token(char *);
int execute(char **);

#endif

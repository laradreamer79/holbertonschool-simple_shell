#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void display_prompt(void);
char *read_line(void);
void execute_command(char **args);
char *trim_spaces(char *str);
char **split_line(char *line);
char *find_in_path(char *command);

#endif

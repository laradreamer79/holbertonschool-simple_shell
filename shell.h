#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

void display_prompt(void);
char *read_line(void);
void execute_command(char *command);
char *trim_spaces(char *str);

#endif

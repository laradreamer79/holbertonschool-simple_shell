#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * prompt - displays the shell prompt
 */
void prompt(void);

/**
 * read_line - reads input from stdin
 *
 * Return: pointer to the input string
 */
char *read_line(void);

/**
 * execute - executes a command
 * @command: command to execute
 *
 * Return: 1 on success, 0 otherwise
 */
int execute(char *command);

extern char **environ;

#endif /* SHELL_H */


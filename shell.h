#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/**
 * prompt - displays the shell prompt
 */
void prompt(void);

/**
 * read_line - reads input from stdin
 * Return: pointer to input string
 */
char *read_line(void);

/**
 * find_path - finds full path of a command using PATH
 * @command: command name
 * Return: full path or NULL
 */
char *find_path(char *command);

/**
 * execute - executes a command
 * @command: command to execute
 * Return: 1 on success
 */
int execute(char *command);

extern char **environ;
char *parse(char *line);

#endif /* SHELL_H */

#include "shell.h"

/**
 * execute - executes a command
 * @command: command to execute
 * Return: 1 always
 */
int execute(char *command)
{
    pid_t pid;
    int status;
    char *argv[2];
    int i;

    if (command == NULL || command[0] == '\0')
        return (1);

    for (i = 0; command[i]; i++)
    {
        if (command[i] == '\n')
        {
            command[i] = '\0';
            break;
        }
    }

    argv[0] = command;
    argv[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }

    if (pid == 0)
    {
        execve(command, argv, environ);
        perror(command);
        exit(EXIT_FAILURE);
    }

    wait(&status);
    return (1);
}

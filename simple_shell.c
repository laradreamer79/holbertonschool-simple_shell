#include "shell.h"
/**
 * display_prompt - Displays the shell prompt (#cisfun$)
 * No parameters, no return value
*/
void display_prompt(void)
{
	printf("#cisfun$");
	fflush(stdout);
}
/**
 * read_line - Reads a line of input from user
 *Return: Pointer to the line, or NULL for Ctrl+D
*/
char *read_line(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read_chars;

	read_chars = getline(&line, &len, stdin);

	if (read_chars == -1)
	{
		free(line);
		return (NULL);
	}

	if (read_chars > 0 && line[read_chars - 1] == '\n')
	{
		line[read_chars - 1] = '\0';
	}
	return (line);
}
/**
 * execute_command - Executes a command using fork/execve
 * @command: The command to execute (full path like /bin/ls)
 * No return value
*/
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *args[2];

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, environ) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

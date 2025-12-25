#include "shell.h"
/**
 * display_prompt - displays shell prompt
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * read_line - reads a line from stdin
 * Return: pointer to line, or NULL on EOF
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
		line[read_chars - 1] = '\0';

	return (line);
}

/**
 * execute_command - executes a command using fork/execve
 * @command: command to execute
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
			fprintf(stderr, "./hsh: No such file or directory\n");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

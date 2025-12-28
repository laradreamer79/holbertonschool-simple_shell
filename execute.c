#include "shell.h"
/**
 * execute_command - executes command with PATH support
 * @args: array of command and arguments
 * Return: exit status
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path;

	if (args == NULL || args[0] == NULL)
		return (0);

	full_path = find_in_path(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return (1);
	}

	if (pid == 0)
	{
		args[0] = full_path;
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			free(full_path);
			_exit(127);
		}
	}

	waitpid(pid, &status, 0);
	free(full_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}


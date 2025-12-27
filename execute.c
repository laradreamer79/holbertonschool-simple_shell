#include "shell.h"
/**
 * execute_command - executes command with PATH support
 * @args: array of command and arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path;
	char *original_cmd = NULL;

	if (args == NULL || args[0] == NULL)
		return;

	full_path = find_in_path(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return;
	}
	else if (pid == 0)
	{
		original_cmd = strdup(args[0]);
		args[0] = full_path;

		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n",
				(original_cmd != NULL) ? original_cmd : args[0]);
			free(full_path);
			free(original_cmd);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(full_path);
	}
}

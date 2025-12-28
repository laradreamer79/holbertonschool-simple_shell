#include "shell.h"
/**
 * main - entry point for simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL;
	char **args = NULL;
	int status = 0;

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		command = read_line();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		args = split_line(command);

		if (args != NULL && args[0] != NULL &&
				strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(command);
			break;
		}
		if (args != NULL && args[0] != NULL)
			status = execute_command(args);
		free(args);
		free(command);
	}
	return (status);
}


#include "shell.h"
/**
 * main - entry point for simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL;
	char **args;

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
		if (args != NULL && args[0] != NULL)
			execute_command(command);
		free(args);
		free(command);
	}
	return (0);
}

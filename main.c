#include "shell.h"
/**
 * main - entry point for simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL;

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

		if (trim_spaces(command) == NULL || strlen(command) == 0)
		{
			free(command);
			continue;
		}

		execute_command(command);
		free(command);
	}
	return (0);
}

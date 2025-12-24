#include "shell.h"
/**
*
*/
int main(int argc, char **argv)
{
	char *command = NULL;

	signal(SIGINT, SIG_IGN);

	(void)argc;
	(void)argv;

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
		if (strlen(command) > 0)
		{
			execute_command(command);
		}
		free(command);
		command = NULL;
	}
	return (0);
}

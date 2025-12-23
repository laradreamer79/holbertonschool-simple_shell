#include "shell.h"

/**
 * main - entry point for simple shell
 *
 * Return: always 0
 */
int main(void)
{
	char *line;
	int status;

	status = 1;
	while (status)
	{
		prompt();
		line = read_line();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		status = execute(line);
		free(line);
	}
	return (0);
}
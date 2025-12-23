#include "shell.h"

/**
 * parse - remove newline from getline input
 * @line: input line from getline
 *
 * Return: command string (same pointer)
 */
char *parse(char *line)
{
	size_t i;

	if (line == NULL)
		return (NULL);

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
	}

	return (line);
}

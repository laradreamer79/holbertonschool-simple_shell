#include "shell.h"

/**
 * read_line - reads a line from standard input
 *
 * Return: pointer to the line read, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

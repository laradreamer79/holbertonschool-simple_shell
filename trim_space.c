#include "shell.h"
/**
 * trim_spaces - removes whitespace from start and end
 * @str: string to clean
 * Return: cleaned string, or NULL if all spaces
 */
char *trim_spaces(char *str)
{
	int i = 0, j = 0;
	int len;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;

	if (str[i] == '\0')
	{
		str[0] = '\0';
		return (NULL);
	}
	j = 0;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';

	len = j;
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' ||
		str[len - 1] == '\n' || str[len - 1] == '\r' ||
		str[len - 1] == '\f' || str[len - 1] == '\v'))
	{
		len--;
	}
	str[len] = '\0';

	return (str);
}
/**
 * split_line - splits a line into tokens
 * @line: the input line
 *
 * Return: array of tokens, NULL-terminated
 */
char **split_line(char *line)
{
	char **args = malloc(10 * sizeof(char *));
	int i = 0;
	char *p = line;

	if (args == NULL)
		return (NULL);

	while (*p == ' ')
		p++;
	if (*p == '\0')
	{
		free(args);
		return (NULL);
	}
	args[i] = p;
	i++;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			*p = '\0';
			p++;
			while (*p == ' ')
				p++;
			if (*p != '\0')
			{
				args[i] = p;
				i++;
				if (i >= 9)
					break;
			}
		}
		else
		{
			p++;
		}
	}
	args[i] = NULL;
	return (args);
}

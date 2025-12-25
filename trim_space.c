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
 * split_line - Splits and cleans a line
 * @line: The line to split
 *
 * Return: Array of tokens
 */
char **split_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	/* Clean the line first */
	if (trim_spaces(line) == NULL)
		return (NULL);

	tokens = malloc(64 * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= 63)
			break;

		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}

#include "shell.h"
/**
 * find_in_path - searches for command in PATH
 * @command: command to search for
 * Return: full path if found, NULL if not
 */
char *find_in_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}
	path = _getenv("PATH");

	if (path == NULL || path[0] == '\0')
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}


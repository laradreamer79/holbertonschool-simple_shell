#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: pointer to the value in environ, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;
	size_t len;

	if (name == NULL || *name == '\0')
		return (NULL);

	len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 &&
		    environ[i][len] == '=')
			return (environ[i] + len + 1);
	}

	return (NULL);
}


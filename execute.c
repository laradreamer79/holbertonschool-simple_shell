#include "shell.h"

/**
 * is_all_spaces - checks if string is only spaces/tabs/newlines
 * @s: input string
 * Return: 1 if only spaces, 0 otherwise
 */
static int is_all_spaces(char *s)
{
	int i;

	if (s == NULL)
		return (1);

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
	}
	return (1);
}

/**
 * build_argv - split line into argv tokens by space/tab
 * @line: input line (will be modified by strtok)
 * Return: NULL-terminated argv array (malloc’d) or NULL
 */
static char **build_argv(char *line)
{
	char **argv;
	char *tok;
	size_t cap = 8, n = 0;

	argv = malloc(sizeof(char *) * cap);
	if (argv == NULL)
		return (NULL);

	tok = strtok(line, " \t");
	while (tok != NULL)
	{
		if (n + 1 >= cap)
		{
			cap *= 2;
			argv = realloc(argv, sizeof(char *) * cap);
			if (argv == NULL)
				return (NULL);
		}
		argv[n++] = tok;
		tok = strtok(NULL, " \t");
	}
	argv[n] = NULL;
	return (argv);
}
/**
 * find_path - finds full path of a command
 * @cmd: command name
 * Return: full path or NULL
 */
char *find_path(char *cmd)
{
	char *path, *path_copy, *dir, *full;
	struct stat st;

	if (cmd == NULL)
		return (NULL);

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			return (NULL);

		strcpy(full, dir);
		strcat(full, "/");
		strcat(full, cmd);

		if (stat(full, &st) == 0)
		{
			free(path_copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
/**
 * execute - executes a command line
 * @command: input line (may contain args)
 * Return: 1 to continue loop
 */
int execute(char *command)
{
	pid_t pid;
	int status;
	char *path;
	char **argv;

	if (command == NULL || is_all_spaces(command))
		return (1);

	argv = build_argv(command);
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return (1);
	}

	path = NULL;
	if (strchr(argv[0], '/') != NULL)
		path = argv[0];
	else
		path = find_path(argv[0]);

	if (path == NULL)
	{
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		free(argv);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (path != argv[0])
			free(path);
		free(argv);
		return (1);
	}

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("./hsh");
		exit(127);
	}

	wait(&status);

	if (path != argv[0])
		free(path);
	free(argv);
	return (1);
}

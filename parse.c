#include "shell.h"

/**
 * parse - cleans input line
 * @line: input from getline
 *
 * Return: cleaned command or NULL
 */
char *parse(char *line)
{
    int i = 0, j = 0;

    if (line == NULL)
        return (NULL);

    /* remove newline */
    while (line[i])
    {
        if (line[i] == '\n')
        {
            line[i] = '\0';
            break;
        }
        i++;
    }

    /* skip leading spaces */
    i = 0;
    while (line[i] == ' ')
        i++;

    /* shift string left */
    while (line[i])
        line[j++] = line[i++];

    line[j] = '\0';

    /* remove trailing spaces */
    j--;
    while (j >= 0 && line[j] == ' ')
        line[j--] = '\0';

    if (line[0] == '\0')
        return (NULL);

    return (line);
}

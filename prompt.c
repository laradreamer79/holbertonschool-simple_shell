#include "shell.h"

/**
 * prompt - displays the shell prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

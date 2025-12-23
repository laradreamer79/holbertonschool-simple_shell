#include <unistd.h>
#include "shell.h"

void prompt(void)
{
    if (isatty(STDIN_FILENO))
       write(STDERR_FILENO, "$ ", 2);
}

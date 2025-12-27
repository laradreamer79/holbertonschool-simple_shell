#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	char *v;

	v = _getenv("PATH");
	if (v)
		printf("PATH=%s\n", v);
	else
		printf("PATH is NULL\n");

	v = _getenv("NOTEXIST_ABC");
	if (v)
		printf("NOTEXIST_ABC=%s\n", v);
	else
		printf("NOTEXIST_ABC is NULL\n");

	return (0);
}


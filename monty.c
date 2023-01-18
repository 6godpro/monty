#include "monty.h"
#include <string.h>
globals_t globals;
/* TODO include documentation */


int main(int ac, char *av[])
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(av[1], &stack);

	free_dstack(stack);
	return (0);
}

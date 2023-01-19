#include "monty.h"

globals_t globals;
/**
 * main - Entry point to monty interpreter.
 * @ac: Argument counter.
 * @av: Array of character pointers listing all
 *	the arguments.
 * Return: Always 0.
 */
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

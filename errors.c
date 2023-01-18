#include "monty.h"

void malloc_error(void)
{
	char *err = "Error: malloc failed\n";
	int len = strlen(err);

	write(2, err, len);
	exit(EXIT_FAILURE);
}

void pop_empty_stack(unsigned int line_num)
{
	char *err = "can't pop an empty stack\n";

	fprintf(stderr, "L%d: %s", line_num, err);
	exit(EXIT_FAILURE);
}

void pint_empty_stack(unsigned int line_num)
{
	char *err = "can't pint, stack empty\n";

	fprintf(stderr, "L%d: %s", line_num, err);
	exit(EXIT_FAILURE);
}


void invalid_op(stack_t *stack, char **buff, unsigned int line_num)
{
	char *err = "unknown instruction";

	fprintf(stderr, "L%d: %s %s\n", line_num, err, buff[0]);
	free(buff);
	free_dstack(stack);
	exit(EXIT_FAILURE);
}

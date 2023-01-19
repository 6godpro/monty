#include "monty.h"

/**
 * malloc_error - Displays error message if memory alloc-
 *		  ation fails.
 */
void malloc_error(void)
{
	char *err = "Error: malloc failed\n";
	int len = strlen(err);

	write(2, err, len);
	exit(EXIT_FAILURE);
}

/**
 * pop_empty_stack - Displays error message if pop is exec-
 *		     uted when the stack is empty.
 * @line_num: Corresponds to the line number in the bytecode
 *	      file.
 */
void pop_empty_stack(unsigned int line_num)
{
	char *err = "can't pop an empty stack\n";

	fprintf(stderr, "L%d: %s", line_num, err);
	exit(EXIT_FAILURE);
}

/**
 * pint_empty_stack - Displays error message if pint is exec-
 *		     uted when the stack is empty.
 * @line_num: Corresponds to the line number in the bytecode
 *	      file.
 */
void pint_empty_stack(unsigned int line_num)
{
	char *err = "can't pint, stack empty\n";

	fprintf(stderr, "L%d: %s", line_num, err);
	exit(EXIT_FAILURE);
}

/**
 * invalid_op - Displays error message if an opcode is not
 *		found.
 * @stack: Pointer to the top of the stack/queue.
 * @buff: Array of strings to be freed before exiting
 * @line_num: Corresponds to the line number in the bytecode
 */
void invalid_op(stack_t *stack, char **buff, unsigned int line_num)
{
	char *err = "unknown instruction";

	fprintf(stderr, "L%d: %s %s\n", line_num, err, buff[0]);
	free(buff);
	free_dstack(stack);
	exit(EXIT_FAILURE);
}

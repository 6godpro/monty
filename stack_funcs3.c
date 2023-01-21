#include "monty.h"


/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pchar - Prints the char at the top of the stack,
 *	   followed by a new line.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}


	printf("%c\n", (*stack)->n);
}


/**
 * pstr - Prints the char at the top of the stack,
 *	   followed by a new line.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	for (; tmp; tmp = tmp->next)
	{
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
	}
	printf("\n");
}

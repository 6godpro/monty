#include "monty.h"

void add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (*stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop(stack, line_num);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}

void sub(stack_t **stack, unsigned int line_num)
{
	int diff;

	if (*stack && (*stack)->next)
	{
		diff = (*stack)->next->n - (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = diff;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}

#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;
	(void)line_num;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error();
	new->n = globals.arg;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *node = *stack;

	if (!node || !stack)
		pop_empty_stack(line_num);

	if (node->next == NULL)
	{
		*stack = NULL;
		return;
	}
	*stack = node->next;
	node->next->prev = NULL;

	free(node);
}

void add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (*stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop(stack, line_num);
		pop(stack, line_num);
		push(stack, sum);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
}


void pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_num)
{
	stack_t *node = *stack;

	if (!node || !stack)
		return;

	for (; node != NULL; node = node->next)
		printf("%d\n", node->n);
}

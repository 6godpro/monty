#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
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

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
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

/**
 * pall - Prints all the values on the stack, starting
 *	  from the top of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_num)
{
	stack_t *node = *stack;

	if (!node || !stack)
		return;

	for (; node != NULL; node = node->next)
		printf("%d\n", node->n);
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
		pint_empty_stack(line_num);

	printf("%d\n", (*stack)->n);
}

/**
 * nop - Opcode nop doesn’t do anything
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

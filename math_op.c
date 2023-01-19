#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of
 *	      instruction in the bytecode file
 *	      that is being executed.
 */
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

/**
 * sub - Subtracts the top element of the stack from
 *	 the second top element of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of instr-
 *	      uction in the bytecode file that is
 *	      being executed.
 */
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


/**
 * _div - Divides the second top element of the
 *	  stack by the top element of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of instr-
 *	      uction in the bytecode file that is
 *	      being executed.
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int div;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_num);
			free(*stack);
			exit(EXIT_FAILURE);
		}
		div = (*stack)->next->n / (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = div;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * mul - Multiplies the second top element of the
 *	 stack with the top element of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of instr-
 *	      uction in the bytecode file that is
 *	      being executed.
 */
void mul(stack_t **stack, unsigned int line_num)
{
	int mult;

	if (*stack && (*stack)->next)
	{
		mult = (*stack)->next->n * (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = mult;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * mod - Computes the rest of the division of the
 *	 second top element of the stack by the top
 *	 element of the stack.
 * @stack: Pointer to the top of the stack/queue.
 * @line_num: Corresponds to the line number of instr-
 *	      uction in the bytecode file that is
 *	      being executed.
 */
void mod(stack_t **stack, unsigned int line_num)
{
	int rem;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_num);
			free(*stack);
			exit(EXIT_FAILURE);
		}
		rem = (*stack)->next->n % (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = rem;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free(*stack);
		exit(EXIT_FAILURE);
	}
}

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals_s - Global variables used within program
 * @fp: The bytecode file.
 * @push_arg: Argument for push function.
 * @str: ...
 */
typedef struct globals_s
{
	FILE *fp;
	int arg;
} globals_t;

extern globals_t globals;

/* Stack Function */
void pop(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);


typedef void (*instruct)(stack_t **stack, unsigned int line_num);

instruct get_func(char *str);
instruct get_func(char *str);
void parse_line(char **buff, unsigned int line_num, stack_t **stack);
void open_file(char *file, stack_t **stack);

/*errors*/
void malloc_error(void);
void pop_empty_stack(unsigned int line_num);
void pint_empty_stack(unsigned int line_num);
void invalid_op(stack_t *stack, char **buff, unsigned int line_num);

/* utils */
void free_dstack(stack_t *head);
int is_number(char *str);
int count_words(char *s, char *delim);
char **line_tokens(char *line, char *delim);


#endif /* MONTY_H */

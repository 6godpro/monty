#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 * line_tokens - Tokenizes a string.
 * @line: The string to be tokenized.
 * @delim: The delimiter.
 * Return: A buffer containing the tokens.
 *	   If error - NULL.
 */
char **line_tokens(char *line, char *delim)
{
	int words, i = 1;
	char **buff;

	if (!line || *line == '\n')
		return (NULL);

	words = count_words(line, delim);

	buff = malloc(sizeof(char *) * (words + 1));
	if (!buff)
		malloc_error();

	buff[0] = strtok(line, delim);

	while ((buff[i] = strtok(NULL, delim)) != NULL)
		i++;

	return (buff);
}

/**
 * get_func - Gets the function that handles
 *	      a particular opcode.
 * @opcode: Operation code to find.
 *
 * Return: The function to handle the opcode
 *	   if found.
 */
instruct get_func(char *opcode)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"div", _div},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pstr", pstr},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (instruct[i].opcode != NULL && strcmp(opcode, instruct[i].opcode) != 0)
		i++;
	return (instruct[i].f);
}

/**
 * parse_line - Analyses a line of instruction.
 * @buff: Contains tokens strings.
 * @line_num: This corresponds with the line number
 *	      in the bytecode file that is to be
 *	      executed.
 * @stack: Pointer to the head of the stack.
 */
void parse_line(char **buff, unsigned int line_num, stack_t **stack)
{
	instruct s;

	if (buff && buff[0])
	{
		s = get_func(buff[0]);
		if (s == NULL)
			invalid_op(*stack, buff, line_num);
		if (strcmp(buff[0], "push") == 0)
		{
			if (!buff[1] || (buff[1] && is_number(buff[1]) == 0))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				free(buff);

				free_dstack(*stack);
				exit(EXIT_FAILURE);
			}
			else
				globals.arg = atoi(buff[1]);
		}
		s(stack, line_num);
	}
}

/**
 * open_file - Opens a bytecode file for
 *	       execution.
 * @file: Bytecode file to be executed.
 * @stack: Pointer to the head of the stack.
 */
void open_file(char *file, stack_t **stack)
{
	char **buff, *line = NULL;
	size_t line_count = 1, n = 0;
	ssize_t r = 0;

	globals.fp = fopen(file, "r");

	if (globals.fp  == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((r = getline(&line, &n, globals.fp)) != -1)
	{
		buff = line_tokens(line, " \n\t\r");
		if (buff != NULL)
		{
			if (buff[0][0] == '#')
			{
				line_count++;
				free(buff);
				continue;
			}
			parse_line(buff, line_count, stack);
		}
		else
			printf("hello");
		line_count++;
		free(buff);
	}
	fclose(globals.fp);
}

/**
 * count_words - Computes the number of words in a string.
 * @s: The string to be analyzed.
 * @delim: The delimeter.
 * Return: The number of words if any.
 */
int count_words(char *s, char *delim)
{
	int words = 0, i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == *delim || s[i + 1] == '\0')
			words++;
	}
	return (words);
}

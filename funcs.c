#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"


char **line_tokens(char *line, char *delim)
{
	int words, i = 1;
	char **buff;

	if (!line || *line == '\n')
		return (NULL);

	words = count_words(line, delim);
	if (words > 2)
		exit(-2);

	buff = malloc(sizeof(char *) * (words + 1));
	if (!buff)
		malloc_error();

	buff[0] = strtok(line, delim);
	
	while ((buff[i] = strtok(NULL, delim)) != NULL)
		i++;

	return (buff);
}


instruct get_func(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push},
		{"pop", pop},
		{"add", add},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	while (instruct[i].opcode != NULL && strcmp(str, instruct[i].opcode) != 0)
		i++;
	return (instruct[i].f);
}


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
			if (!buff[1] || (buff[1] && is_digit(buff[1]) == 0))
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
			parse_line(buff, line_count, stack);
		}
		line_count++;
		free(buff);
	}
	fclose(globals.fp);
}


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

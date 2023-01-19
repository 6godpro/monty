#include "monty.h"
/**
 * is_number - Checks if a string is a number
 * @str: The string to be checked.
 * Return: If the string is a number - 1
 *	   O/w - 0.
 */
int is_number(char *str)
{
	int i;

	for (i = 0; str[i] && str[i] != '\n'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		return (0);
	}
	return (1);
}

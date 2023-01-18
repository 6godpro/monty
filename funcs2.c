#include "monty.h"

int is_digit(char *str)
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

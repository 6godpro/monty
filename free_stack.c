#include "monty.h"

/**
 * free_dstack - Frees a dlistint_t list.
 * @head: Head pointer to the list to be freed.
 */
void free_dstack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

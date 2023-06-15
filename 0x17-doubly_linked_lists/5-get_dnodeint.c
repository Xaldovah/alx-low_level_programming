#include "lists.h"

/**
 * get_dnodeint_at_index - ...
 * @head: ...
 * @index: ...
 *
 * Return: The nth node of a dlistint_t linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int i;

	curr = head;
	for (i = 0; i < index && curr != NULL; i++)
	{
		curr = curr->next;
	}
	return (curr);
}

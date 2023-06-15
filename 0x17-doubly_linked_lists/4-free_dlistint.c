#include "lists.h"

/**
 * free_dlistint - ...
 * @head: ...
 *
 * Return: None expected.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

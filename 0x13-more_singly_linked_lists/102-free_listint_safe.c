#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list with a loop
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current;
	int deff;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h)
	{
		deff = *h - (*h)->next;
		if (deff > 0)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}

	*h = NULL;

	return (size);
}

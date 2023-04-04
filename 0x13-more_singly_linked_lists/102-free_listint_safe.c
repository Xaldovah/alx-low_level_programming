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
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size++;
		next = current->next;
		free(current);
		current = next;

		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (size);
}


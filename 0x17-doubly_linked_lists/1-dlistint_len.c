#include "lists.h"

/**
 * dlistint_len - ...
 * @h: ...
 *
 * Return: The number of elements.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}

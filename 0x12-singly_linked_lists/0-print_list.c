#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the beginning of the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (h->str)
			printf("[%d] %s\n", h->len, h->str);

		else
			printf("[0] (nil)\n");

	h = h->next;
	count++;
	}

	return (count);
}

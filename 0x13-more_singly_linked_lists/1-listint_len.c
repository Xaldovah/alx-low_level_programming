#include <stdio.h>
#include "lists.h"

/**
 * listint_len - Counts the elemts in a linked list
 * @h: The head of the linked list
 *
 * Return: The number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
	int count = 0;

	if (h != 0)
	{
		while (h)
		{
			h = h->next;
			count++;
		}
	}

	return (count);
}

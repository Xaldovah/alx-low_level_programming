#include <stdio.h>
#include "lists.h"

/**
  * print_listint - function that prints all the elements of a listint
  * @h: The head of the linked list
  *
  * Return: The number of nodes
  */

size_t print_listint(const listint_t *h)
{
	/* Initialize a counter for the number of nodes in the list */
	int count = 0;

	/* Check if the head of the list is not NULL */
	if (h != NULL)
	{

	/* Traverse the list and print each node's value */
		while (h)
		{
			printf("%d\n", h->n);
			h = h->next;
			count++; /* Increment the counter for each node visited */
		}
	}

	/* Return the total number of nodes in the list */
	return (count);
}

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
	// Initialize a counter for the number of nodes in the list
	int count = 0;

	// Check if the head of the list is not NULL
	if (h != 0)
	{
		// Traverse the list and increment the counter for each node visited
		while (h)
		{
			h = h->next; // Move to the next node
			count++; // Increment the counter for each node visited
		}
	}

	return (count); // Return the total number of nodes in the list
}

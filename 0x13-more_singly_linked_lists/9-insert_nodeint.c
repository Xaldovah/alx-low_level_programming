#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head:  A pointer to a pointer to the first node of the linked list
 * @idx: The index at which to insert the new node
 * @n: The value to be strored in the new node
 *
 * Return: If the index is greater than the length of the linked list, return NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *iter;
	unsigned int count = 1;

	if (head) // Check if the head is not NULL
	{
		// Allocate memory for the new node
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		// Set the value of the new node
		new_node->n = n;
		if (idx > 0)
		{
			iter = *head;

			// Iterate through the list to find the node at the specified index
			while (iter)
			{
				if (count == idx)
				{
					new_node->next = iter->next;
					iter->next = new_node;
					return (new_node);
				}
				iter = iter->next;
				count++;
			}
			// If the index is out of range, return NULL
			if (idx > count)
				return (NULL);
		}
		else
		{
			// If index is 0, make the new node the new head
			new_node->next = *head;
			*head = new_node;
		}
		// Return the new node
		return (new_node);
	}
	// If the head is NULL, return NULL
	return (NULL);
}

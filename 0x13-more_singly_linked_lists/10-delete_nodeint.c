#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given index of a linked list.
 * @head: double pointer to the head of the linked list.
 * @index: The index of the node to be deleted
 *
 * Return: 1 if successful, -1 if not.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 1;
	listint_t *new = *head, *temp;

	// Check if the head is NULL or the pointer to the head is NULL
	if (!head || !*head)
		return (-1);

	// If the index is 0, delete the first node
	if (index == 0)
	{
		*head = new->next;
		free(new);
		return (1);
	}

	// Traverse the list until the node at the given index is found
	temp = *head;
	while (temp)
	{
		if (count == index)
		{
			// Delete the node
			new = temp->next;
			temp->next = new->next;
			free(new);
			return (1);
		}

		temp = temp->next;
		count++;
	}

	// If the index is out of bounds, return -1
	return (-1);
}

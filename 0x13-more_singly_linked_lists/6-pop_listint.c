#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node
 * @head - The head of the list
 *
 * Return: The updated list after deletion
 */

int pop_listint(listint_t **head)
{
	listint_t *new_head;
	int n = 0;

	// Check if the head pointer is not NULL
	if (*head != NULL)
	{
		// Save the next node in the list
		new_head = (*head)->next;

		// Save the integer value of the current node
		n = (*head)->n;

		// Free the memory allocated for the current node
		free(*head);

		// Update the head pointer to the next node in the list
		*head = new_head;
	}

	// Return the value of the removed node
	return (n);
}

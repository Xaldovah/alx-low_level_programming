#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - Frees a list
 * @head: The head of the linked list
 *
 * Return: ...
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	// Check if the input pointer is NULL or points to NULL
	if (head == NULL || *head == NULL)
	{
		return;
	}


	// Use a while loop to traverse the list and free each node	
	while (*head)
		{
			// Save the current node in a temporary pointer
			temp = (*head);

			// Update the head pointer to the next node
			*head = (*head)->next;

			// Free the memory allocated for the current node
			free(temp);
		}
	// Free the memory allocated for the head pointer itself
	// It is important even though *head is now NULL
	free(*head);
	
	// Set the input pointer to NULL to avoid dangling pointers
	*head = NULL;
}

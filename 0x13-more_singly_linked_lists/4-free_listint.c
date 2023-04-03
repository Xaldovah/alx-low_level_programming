#include <stdio>
#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: The head of the linked list
 *
 * Return: Nothing
 */

void free_listint(listint_t *head)
{
	// Declare a temporary pointer to store the current node
	listint_t *temp;

	// Use a while loop to traverse the list and free each node
	while (head)
	{
		// Save the current node in a temporary pointer
		temp = head;

		// Update the head pointer to the next node
		head = head->next;
		
		// Free the memory allocated for the current node
		free(temp);
	}

	// Free the memory allocated for the head pointer
	// Even though head is now NULL it is necessary
	free(head);
}

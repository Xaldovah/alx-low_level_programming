#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node to the end of a linked list
 * @head: The head of the linked list
 * @n: The value to add to the end of the linked list
 *
 * Return: The address of the new element, or NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_list, *temp;

	// Check if the double pointer to the head of the list is not NULL
	if (head)
	{
		// Allocate memory for a new node in the list
		new_list = malloc(sizeof(listint_t));
		if (new_list == NULL)
			return (NULL);

		// Initialize the new node with the given value and NULL as its next node
		new_list->n = n;
		new_list->next = NULL;

		// Check if the list is currently empty
		if (*head == NULL)
		{
			// If it is, set the new node as the head of the list and return a pointer to it
			*head = new_list;
			return (*head);
		}
		else
		{
			// If it is not empty, traverse the list until the end and add the new node there
			temp = *head;
			while (temp->next)
				temp = temp->next;

			temp->next = new_list;
			return (temp);
		}
	}

	// Return NULL if the double pointer to the head of the list is NULL
	return (NULL);
}

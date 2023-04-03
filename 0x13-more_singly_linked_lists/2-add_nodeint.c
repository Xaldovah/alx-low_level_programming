#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked list
 * @head: The head of the linked list
 * @n: The value to add to the new node
 *
 * Return: The address of the new element, or NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_list;

	// Check if the double pointer to the head of the list is not NULL
	if (head !== NULL)
	{
		// Allocate memory for a new node in the list
		new_list = malloc(sizeof(listint_t));
		// Check if new list is NULL, if true return NULL
		if (new_list == NULL)
			return (NULL);

		// Initialize the new node with the given value and the current head of the list as its next node
		new_list->n = n;
		new_list->next = *head;

		// Update the head of the list to point to the new node
		*head = new_list;

		// Return a pointer to the new node
		return (new_list);
	}

	// Return NULL if the double pointer to the head of the list is NULL
	return (NULL);
}

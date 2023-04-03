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

	if (*head != NULL)
	{
		new_head = (*head)->next;
		n = (*head)->n;
		free(*head);
		*head = new_head;
	}

	return (0);
}

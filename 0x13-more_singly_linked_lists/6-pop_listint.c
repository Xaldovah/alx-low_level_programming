#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to a pointer to the head node of the list
 *
 * Return: the data of the deleted head node, or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *current_node;
	int n = 0;

	if (*head != NULL)
	{
		current_node = (*head)->next;
		n = (*head)->n;
		free(*head);
		*head = current_node;
	}
	return (n);
}

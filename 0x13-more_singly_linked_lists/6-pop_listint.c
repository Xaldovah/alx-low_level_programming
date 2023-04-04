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
	int data;

	if (*head == NULL)
		return (0);

	current_node = *head;
	data = current_node->n;
	*head = current_node->next;
	free(current_node);

	return (data);
}

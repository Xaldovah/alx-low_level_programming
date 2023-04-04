#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head node of the list
 * @index: index of the node, starting at 0
 *
 * Return: pointer to the nth node, or NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node;

	current_node = head;

	for (i = 0; i < index && current_node != NULL; i++)
		current_node = current_node->next;

	if (i == index && current_node != NULL)
		return (current_node);

	return (NULL);
}

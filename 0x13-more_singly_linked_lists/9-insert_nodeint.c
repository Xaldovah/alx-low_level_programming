#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to a pointer to the head of the linked list.
 * @idx: index of the list where the new node should be added.
 * @n: value to be assigned to the new node.
 *
 * Return: address of the new node. NULL if failed to insert the node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node, *prev_node, *current_node;

	if (!head)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	current_node = *head;
	for (i = 0; current_node && i < idx; i++)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	if (i < idx)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	prev_node->next = new_node;
	new_node->next = current_node;

	return (new_node);
}


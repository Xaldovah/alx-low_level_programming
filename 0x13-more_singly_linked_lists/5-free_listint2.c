#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: pointer to a pointer to the head node of the list
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *current_node;

	if (head)
	{

	while (*head != NULL)
	{
		current_node = *head;
		*head = (*head)->next;
		free(current_node);
	}
	}
	else
	{
		return;
	}

	free(*head);
	head = 0;
}

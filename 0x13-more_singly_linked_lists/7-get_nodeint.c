#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - gets the nth node of a listint_t linked list
 * @head: This is the head 
 * @index: It is the index of the node, starting 0
 *
 * Return: If the node does not exist, returns NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head) // Check if the linked list is not empty
	{
		while (head)
		{
			if (count == idex) // Check if the current node ndex matches the desired index
				return (head);
			head = head->next; // Move to the next node in the linked list
			count++;
		}
	}

	return (NULL); // return NULL if the desire index is out of bounds
}

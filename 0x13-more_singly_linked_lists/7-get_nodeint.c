#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - ...
 * @head: ...
 * @index: ...
 *
 * Return: ...
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head)
	{
		while (head)
		{
			if (count == idex)
				return (head);
			head = head->next;
			count++;
		}
	}

	return (NULL);
}

#include "lists.h"

/**
 * delete_dnodeint_at_index - ...
 * @head: ...
 * @index: ...
 *
 * Return: 1 if succeeds, -1 otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = NULL, *temp = NULL;
	unsigned int length = 0;

	if (head && *head)
	{
		length = dlistint_len(*head);
		if (index > length)
			return (-1);

		if (index == 0)
			return (delete_first_dnode(head));
		current = get_dnodeint_at_index(*head, index);
		if (current)
		{
			temp = current;
			if (length - 1 == index)
				current->prev->next = current->next;
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			free(temp);
			return (1);
		}
	}
	return (-1);
}

/**
  * delete_first_dnode - ...
  * @head: ...
  *
  * Return: 1 if it is deleted
  */
int delete_first_dnode(dlistint_t **head)
{
	dlistint_t *current = *head, *temp = NULL;

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*head = current;
	}
	else
	{
		*head = NULL;
	}

	free(temp);
	return (1);
}

/**
 * get_dnodeint_at_index - ...
 * @head: ...
 * @index: ...
 *
 * Return: The nth node of a dlistint_t linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int i;

	curr = head;
	for (i = 0; i < index && curr != NULL; i++)
	{
		curr = curr->next;
	}
	return (curr);
}

/**
 * dlistint_len - ...
 * @h: ...
 *
 * Return: The number of elements.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}

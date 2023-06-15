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
  * Return: The specific node of the doubly linked list
  */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int iter_times = 0;

	if (head)
	{
		while (current != NULL)
		{
			if (iter_times == index)
				return (current);

			current = current->next;
			++iter_times;
		}
	}

	return (NULL);
}

/**
  * dlistint_len - ...
  * @h: ...
  *
  * Return: Number of elements in the doubly linked list
  */
size_t dlistint_len(const dlistint_t *h)
{
	int lenght = 0;

	while (h != NULL)
	{
		++lenght;
		h = h->next;
	}

	return (lenght);
}

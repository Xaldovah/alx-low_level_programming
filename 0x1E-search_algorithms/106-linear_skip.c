#include "search_algos.h"

/**
 * linear_skip - Search for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *next;

	if (list == NULL)
		return (NULL);

	while (current != NULL)
	{
		next = current->next;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

		if (next == NULL || next->n >= value)
		{
			if (next != NULL)
				printf("Value found between indexes [%lu] and [%lu]\n",
						current->index, next->index);
			else
				printf("Value found between indexes [%lu] and [%lu]\n",
						current->index, current->index);
			while (current != NULL)
			{
				printf("Value checked at index [%lu] = [%d]\n",
						current->index, current->n);
				if (current->n == value)
					return (current);
				current = current->next;
			}
			break;
		}
		current = next;
	}
	return (NULL);
}

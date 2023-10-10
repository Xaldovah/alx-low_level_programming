#include "search_algos.h"

/**
 * jump_list - Search for value in a sorted list of integers using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node, or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *current = list;
	size_t step = sqrt(size);
	size_t prev = 0, i;

	if (list == NULL)
	{
		return (NULL);
	}
	while (current != NULL && current->n < value)
	{
		prev = current->index;
		for (i = 0; i < step && current->next != NULL; i++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev, current->index);

	current = list;
	while (current != NULL && current->index < prev)
		current = current->next;
	while (current != NULL && current->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

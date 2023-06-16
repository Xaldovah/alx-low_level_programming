#include "lists.h"

/**
 * sum_dlistint - ...
 * @head: ...
 *
 * Return: The sum of all the date(n) of a dlistint_t list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

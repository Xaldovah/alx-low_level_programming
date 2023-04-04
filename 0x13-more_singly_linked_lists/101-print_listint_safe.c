#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely (detects loops).
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			printf("(nil), (nil)\n");
			exit(98);
		}
	}

	if (slow != NULL)
		printf("[%p] %d\n", (void *)slow, slow->n);

	return (0);
}



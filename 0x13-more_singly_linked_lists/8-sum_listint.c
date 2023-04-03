#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data (n) in a listint_t linked list
 * @head: Pointer to the first node in the linked list
 *
 * Return: Sum of all the data in the linked list, or 0 if it is empty
 */

int sum_listint(listint_t *head)
{
	int amount = 0;

	if (head) // Check if the linked list is not empty
	{
		while (head)
		{
			amount += head->n; // Add the current node's data to the running total
			head = head->next; // Move to the next node in the linked list
		}
	}

	return (amount); // Return the total sum
}

#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: Number to find index
 * @index: Index to find
 *
 * Return: The value of the bit at the given index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit_index = 0;

	/* Loop through the bits of the number */
	while (n)
	{
		/* Check if the current bit is the one we're looking for */
		if (bit_index == index)
		{
			/* If it is, return its value */
			if (n % 2)
				return (1);
			else
				return (0);
		}

		/* Move to the next bit */
		n = n / 2;
		bit_index++;
	}

	/* If the index is out of range, return 0 */
	if (index > bit_index && index < 63)
		return (0);

	/* If an error occurs, return -1 */
	return (-1);
}

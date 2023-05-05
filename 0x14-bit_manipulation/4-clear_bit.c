#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @index: The index, starting from 0 of the bit you want to set
 * @n: The number containing the bit
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if index is out of range */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Use bitwise AND to clear the bit at the given index */
	*n &= ~(1UL << index);
	return (1);
}

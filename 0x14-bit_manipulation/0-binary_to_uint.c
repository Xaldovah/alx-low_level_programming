#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_to_uint - converts a binary number to an unsigned int
 *@b: Binary string to convert
 *
 * Return: The converted number or 0 if b is NULL or a char is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int len, total = 0, sum = 0;

	if (b == 0)
		return (0);

	len = _strlen(b);
	for (unsigned int i = 0; i < len; i++)
	{
		if (b[i] != 48 && b[i] != 49)
			return (0);
		if (b[i] == 49)
			sum += 1 << total;

		total++;
	}

	return (sum);
}

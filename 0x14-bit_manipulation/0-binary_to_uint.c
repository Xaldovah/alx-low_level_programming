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
	unsigned int length, total = 0, sum = 0;

	if (b == NULL)
		return (0);

	length = _strlen(b);
	while (length--)
	{
		if (b[length] != 48 && b[length] != 49)
			return (0);
		if (b[length] == 49)
			sum += 1 << total;

		total++;
	}

	return (sum);
}

int _strlen(const char *s)
{
	int c = 0;

	while (s[c])
		c++;

	return (c);
}

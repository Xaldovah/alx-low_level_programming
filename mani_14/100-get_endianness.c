#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_endianness - Checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	/* Create an integer and assign it value 1 */
	int i = 1;
	/* Create a char pointer c and point it to memory location of i */
	char *c = (char *)&i;

	/* Check if the value stored at mem loc pointed by c is non-zero */
	if (*c)
	{
		/* If so, it means the system is little-endian, so return 1 */
		return (1);
	}
	else
	{
		/* Otherwise the system is big-endian, so return 0 */
		return (0);
	}
}



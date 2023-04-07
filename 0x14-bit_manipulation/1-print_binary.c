#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int len = sizeof(unsigned long int) * 8;

	while (len--)
	{
		if ((mask << len) & n)
			_putchar('1');
		else
			_putchar('0');
	}
}

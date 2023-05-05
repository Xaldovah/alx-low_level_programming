#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	_print_binary(n);
}
/**
 * _print_binary - Finds number
 * @n: The number
 *
 * Return: void
 */

void _print_binary(unsigned long int n)
{
	if (n < 1)
		return;

	_print_binary(n >> 1);

	if (n & 1)
		_putchar('1');
	else
		_putchar('0');
}

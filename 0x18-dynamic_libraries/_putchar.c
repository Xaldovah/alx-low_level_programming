#include "main.h"

/**
 * _putchar - writes a single character to the standard output
 * @c: ...
 * Return: ...
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * _memset - fills a block of memory with a specified value
 * @s: ...
 * @b: ...
 * @n: ...
 * Return: ...
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

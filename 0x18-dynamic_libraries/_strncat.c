#include "main.h"

/**
 * _strncat - concatenates a specified number of chars from one str to another
 * @dest: ...
 * @src: ...
 * @n: ...
 * Return: ...
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

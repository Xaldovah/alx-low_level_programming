#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: ...
 * @src: ...
 * Return: ...
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

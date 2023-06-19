#include "main.h"

/**
 * _strchr - searches for the first occurrence of a character in a string
 * @s: ...
 * @c: ...
 * Return: NULL
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

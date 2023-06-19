#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: ...
 * Return: ...
 */
int _atoi(char *s)
{
	int sign = 1, result = 0, i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (sign * result);
}

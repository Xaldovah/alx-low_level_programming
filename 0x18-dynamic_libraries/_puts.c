#include "main.h"

/**
 * _puts - writes a string to standard output followed by a newline character
 * @s: ...
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
}

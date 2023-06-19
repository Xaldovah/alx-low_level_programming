#include "main.h"

/**
 * _isalpha - checks if a character is alphabetic
 * @c: ...
 * Return: ...
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

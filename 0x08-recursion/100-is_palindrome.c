#include "main.h"

int is_palindrome(char *s);
int check_palindrome(char *start, char *end);

/**
 * is_palindrome - Returns if a string is palindrome
 * @s: the string value to be checked
 *
 * Return: integer value
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);

	char *end = s;
	while (*end != '\0')
		end++;

	return (check_palindrome(s, end - 1));
}

/**
 * check_palindrome - Check if a string is palindrome
 * @start: pointer to the start of the string
 * @end: pointer to the end of the string
 *
 * Return: integer value
 */
int check_palindrome(char *start, char *end)
{
	if (start >= end)
		return (1);

	if (*start != *end)
		return (0);

	return (check_palindrome(start + 1, end - 1));
}

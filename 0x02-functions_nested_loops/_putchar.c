#include <unistd.h>
/**
 * main - program that prints _putchar
 *
 * Return: 0 (success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

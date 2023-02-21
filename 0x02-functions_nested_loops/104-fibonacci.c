#include <stdio.h>

/**
 * main - Prints the first 98 fibonacci numbers
 *
 * Return: Nothing!
 */
int main(void)
{
	int i;


	unsigned long j = 1, k = 2, next;

	printf("%lu, %lu", j, k);

	for (i = 2; i < 98; i++)
	{
		next = j + k;
		j = k;
		k = next;
		printf(", %lu", next);
	}

	printf("\n");

	return (0);
}

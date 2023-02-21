#include <stdio.h>

/**
  * main - Prints the first 98 fibonacci numbers
  *
  * Return: Nothing!
  */
int main(void)
{
	int i = 0;
	unsigned long long j = 1, k = 2;

	while (i < 98)
	{
		if (i == 0)
			printf("%llu", j);
		else if (i == 1)
			printf(", %llu", k);
		else
		{
			k += j;
			j = k - j;
			printf(", %llu", k);
		}

		++i;
	}

	printf("\n");

	return (0);
}

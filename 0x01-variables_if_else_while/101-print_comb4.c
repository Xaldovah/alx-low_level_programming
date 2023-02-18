#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible combinations of three digits
 * separated by , and a space. The three digits must be different
 * and in ascending order. The combinations are printed in the
 * smallest order.
 * Return: Always 0 (Success)
 */

int main(void)
{
	int d, p, q;

	for (d = '0'; d <= '7'; d++)
	{
		for (p = d + 1; p <= '8'; p++)
		{
			for (q = p + 1; q <= '9'; q++)
			{

				if (d != p && d != q && p != q)
				{
					putchar(d);
					putchar(p);
					putchar(q);
					if (d == '7' && p == '8' && q == '9')
						continue;
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}


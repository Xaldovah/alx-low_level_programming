#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * main - Entry point
 * Program 101-Crackme.
 * Return: Always 0.
 */

int main(void)
{
    char password[84];
    int index = 0, sum = 0, diff_half1, diff_half2;

    srand(time(NULL));

    while (sum < 2772)
    {
        password[index] = 33 + rand() % 94;
        sum += password[index++];
    }

    password[index] = '\0';

    if (sum != 2772)
    {
        diff_half1 = (sum - 2772) / 2;
        diff_half2 = (sum - 2772) / 2;

        if ((sum - 2772) % 2 != 0)
        {
            diff_half1++;
        }

        for (index = 0; password[index]; index++)
        {
            if (password[index] >= (33 + diff_half1))
            {
                password[index] -= diff_half1;
                sum -= diff_half1;
            }
        }

        for (index = 0; password[index]; index++)
        {
            if (sum == 2772)
            {
                break;
            }

            if (password[index] >= (33 + diff_half2))
            {
                password[index] -= diff_half2;
                sum -= diff_half2;
            }
        }
    }

    printf("%s", password);

    return 0;
}

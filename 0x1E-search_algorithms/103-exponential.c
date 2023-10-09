#include "search_algos.h"

/**
 * exponential_search - Search for a value in a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found or `array` is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	int pointer;

	if (size == 0)
	{
		return (-1);
	}
	pointer = 1;
	while (pointer < size && array[pointer] < value)
	{
		pointer *= 2;
	}
	return (binary_search(array, value, pointer/2, min(pointer + 1, size)))
}


/**
 * binary_search - Search for a value in a sorted array using binary search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found or `array` is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
	int i, left = 0, mid, right = (int)size - 1;

	if (array == NULL)
	{
		return (-1);
	}

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");

		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);

			if (i < right)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}
		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (-1);
}

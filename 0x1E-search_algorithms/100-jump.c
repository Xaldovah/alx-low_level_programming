#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using jump search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found or `array` is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int i, step, prev;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	step = (int)sqrt(size);
	prev = 0;

	printf("Value checked array[0] = [%d]\n", array[0]);

	while (array[prev] < value && prev < (int)size)
	{
		prev += step;
		if (prev < (int)size)
		{
			printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		}
	}
	printf("Value found between indexes [%d] and [%d]\n", prev - step, prev);

	for (i = prev - step; i <= prev && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}

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
	int i, step, current;

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	step = (int)sqrt(size);
	current = 0;

	while (current < size && array[current] < value)
	{
		printf("Value checked array[%d] = [%d]\n", current, array[current]);
		current += step;
	}
	if (current >= size)
	{
		return (-1);
	}
	if (array[current] == value)
	{
		return (current);
	}
	for (i = current; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}

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
	int bound = 1;
	int left, right, mid;

	if (array == NULL || size == 0)
		return (-1);
	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	left = bound / 2;
	right = bound < (int)size ? bound : (int)size - 1;
	printf("Value found between indexes [%d] and [%d]\n", left, right);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (mid = left; mid <= right; mid++)
		{
			printf("%d", array[mid]);
			if (mid < right)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}
		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

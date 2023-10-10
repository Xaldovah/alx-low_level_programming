#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive helper func for advanced binary search
 * @array: Pointer to the first element of the sorted array
 * @low: The low index of the current subarray
 * @high: The high index of the current subarray
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found.
 */
int advanced_binary_recursive(int *array, int low, int high, int value)
{
	int i, mid;

	if (low > high)
	{
		return (-1);
	}
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}
	mid = low + (high - low) / 2;
	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
		{
			return (mid);
		}
		else
		{
			return (advanced_binary_recursive(array, low, mid, value));
		}
	}
	else if (array[mid] < value)
	{
		return (advanced_binary_recursive(array, mid + 1, high, value));
	}
	else
	{
		return (advanced_binary_recursive(array, low, mid - 1, value));
	}
}


/**
 * advanced_binary - Search for a value in a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found or `array` is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}
	return (advanced_binary_recursive(array, 0, size - 1, value));
}

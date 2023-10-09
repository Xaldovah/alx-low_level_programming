#include "search_algos.h"

/**
 * interpolation_search - Search for a value in a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, -1 if not found or `array` is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0, mid, high = size - 1;

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	while ((array[high] != array[low]) && (value >= array[low]) && (
				value <= array[high])) {
		mid = low + ((value - array[low]) * (high - low) / (
					array[high] - array[low]));
		printf("Value checked array[%lu] = [%lu]\n", (
					unsigned long int)mid, (
						unsigned long int)array[mid]);
		if (array[mid] < value)
		{
			low = mid + 1;
		}
		else if (value < array[mid])
		{
			high = mid - 1;
		}
		else
		{
			return (mid);
		}
	}

	if (value == array[low])
	{
		return (low);
	}
	else
	{
		printf("Value checked array[%lu] is out of range\n", (unsigned long int)mid);
		return (-1);
	}
}

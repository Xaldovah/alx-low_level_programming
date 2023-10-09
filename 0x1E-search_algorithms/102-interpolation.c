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

	while ((arr[high] != arr[low]) && (key >= arr[low]) && (
				key <= arr[high])) {
		mid = low + ((key - arr[low]) * (high - low) / (
					arr[high] - arr[low]));
		if (arr[mid] < key)
		{
			low = mid + 1;
		}
		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			return (mid);
		}
	}

	if (key == arr[low])
	{
		return (low);
	}
	else
	{
		return (-1);
	}
}

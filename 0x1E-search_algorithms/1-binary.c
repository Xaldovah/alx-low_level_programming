#include <stdio.h>

/**
 * binary_search - Search for a value in a sorted array using binary search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where `value` is located, or -1 if not found or `array` is NULL.
 */
int binary_search(int *array, size_t size, int value)
{

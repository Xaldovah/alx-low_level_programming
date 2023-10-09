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

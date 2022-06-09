#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, size, 0, size - 1);
}

/**
 * quick_sort_helper - Helper function for quick_sort
 *
 * @array: Array of integers
 * @size: Size of the array
 * @left: Start index
 * @right: End index
 */
void quick_sort_helper(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, size, left, right);
		quick_sort_helper(array, size, left, pivot - 1);
		quick_sort_helper(array, size, pivot + 1, right);
	}
}

/**
 * partition - Partitions the array
 *
 * @array: Array of integers
 * @size: Size of the array
 * @left: Index of the first element
 * @right: Index of the second element
 * Return: Index of i
 */
int partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = (left - 1), j = 0;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(array, i + 1, right);
	if (array[right] != pivot)
		print_array(array, size);
	return (i + 1);
}

/**
 * swap - Swaps two elements of an array
 *
 * @array: Array of integers
 * @left: Index of the first element
 * @right: Index of the second element
 */
void swap(int *array, int left, int right)
{
	int temp = array[left];

	array[left] = array[right];
	array[right] = temp;
}

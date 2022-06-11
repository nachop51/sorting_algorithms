#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */

void quick_sort_hoare(int *array, size_t size)
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
		quick_sort_helper(array, size, pivot, right);
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
	int i = left - 1;
	int j = right + 1;
	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return i;
		}

		swap(array, i, j);
		print_array(array, size);
	}
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

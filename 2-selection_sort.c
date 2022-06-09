#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, x, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		x = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[x])
				x = j;
		}
		if (x != i)
		{
			temp = array[i];
			array[i] = array[x];
			array[x] = temp;
			print_array(array, size);
		}
	}
}

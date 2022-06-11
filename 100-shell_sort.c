#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: Array of integers
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, temp, j;

	if (!array || size < 2)
		return;
	while (gap < (int)size / 3)
		gap = 3 * gap + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

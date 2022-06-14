#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i = 0, *count, *output;

	if (!array || size < 2)
		return;

	for (max = array[0], i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

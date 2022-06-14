#include "sort.h"

void radix_sort(int *array, size_t size)
{
	int *helper, max = 0;

	if (!array || size < 2)
		return;
	helper = malloc(sizeof(int) * size);
	if (!helper)
		return;

	max = get_max(array, size);
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		}
}

int get_max(int *array, size_t size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
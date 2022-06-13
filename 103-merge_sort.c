#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_helper(array, 0, size - 1);
}

void merge_sort_helper(int *array, int left, int right)
{
	int mid = (right - left) / 2;

	if (right - left <= 1)
		return;

	merge_sort_helper(array, left, mid);
	merge_sort_helper(array, mid, right);
	merge_sorted_arrays(array, left, mid, right);
}

void merge_sorted_arrays(int *array, int left, int mid, int right)
{
	int left_length = mid - left, right_length = right - mid + 1;
	int l, r, temp, k, j;
	int *temp_array;

	temp_array = malloc(sizeof(int) * (left_length + right_length));
	if (!temp_array)
		return;

	printf("Merging...\n[left]: ");
	for (l = 0; l < left_length; l++)
	{
		if (l)
			printf(", ");
		temp_array[l] = array[left + l];
		printf("%d", temp_array[l]);
	}
	temp = l;
	printf("\n[right]: ");
	for (r = l, j = 0; r < left_length + right_length; r++, j++)
	{
		if (r != temp)
			printf(", ");
		temp_array[l + j] = array[left + l + j];
		printf("%d", temp_array[l + j]);
	}
	for (l = 0, r = temp, k = left; k <= right; k++)
	{
		if ((l < left_length) && ((r - temp >= right_length) || (temp_array[l] <= temp_array[r])))
		{
			array[k] = temp_array[l];
			l++;
		}
		else
		{
			array[k] = temp_array[r];
			r++;
		}
	}
	printf("\n[Done]: "), print_array(array, 10);
	free(temp_array);
}
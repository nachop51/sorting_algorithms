#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *helper;

	if (!array || size < 2)
		return;
	helper = malloc(sizeof(int) * size);
	if (!helper)
		return;
	copy_array(array, 0, size, helper);
	merge_sort_helper(helper, 0, size, array);
}

/**
 * merge_sort_helper - Sorts an array of integers in ascending order
 * @helper: Array of integers
 * @left: Left index of the array
 * @right: Right index of the array
 * @array: Array of integers
 */
void merge_sort_helper(int helper[], int left, int right, int array[])
{
	int mid;

	if (right - left <= 1)
		return;
	mid = (right + left) / 2;
	merge_sort_helper(array, left, mid, helper);
	merge_sort_helper(array, mid, right, helper);
	merge_sorted_arrays(helper, left, mid, right, array);
}

/**
 * merge_sorted_arrays - Merges two sorted arrays into one
 * @array: Array of integers
 * @left: Left index of the array
 * @mid: Middle index of the array
 * @right: Right index of the array
 * @h: Array of integers
 */
void merge_sorted_arrays(int array[], int left, int mid, int right, int h[])
{
	int i = left, j = mid, k;

	printf("Merging...\n[left]: ");
	for (k = left; k < mid; k++)
	{
		if (k != left)
			printf(", ");
		printf("%d", array[k]);
	}
	printf("\n[right]: ");
	for (k = mid; k < right; k++)
	{
		if (k != mid)
			printf(", ");
		printf("%d", array[k]);
	}
	printf("\n[Done]: ");
	for (k = left; k < right; k++)
	{
		if (k != left)
			printf(", ");
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			h[k] = array[i];
			i = i + 1;
		}
		else
		{
			h[k] = array[j];
			j = j + 1;
		}
		printf("%d", h[k]);
	}
	putchar(10);
}

/**
 * copy_array - Copies an array to another array
 *
 * @array: Array to copy
 * @start: Start index of the array
 * @end: End index of the array
 * @helper: Array to copy to
 */
void copy_array(int *array, int start, int end, int *helper)
{
	int i;

	for (i = start; i < end; i++)
		helper[i] = array[i];
}

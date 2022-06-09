#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: Array to sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int temp, sorted = 0;

	if (!array || size < 2)
		return;

	for (; !sorted; sorted = isSorted(array, size, NULL))
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

/**
 * isSorted - Checks if a collection is sorted
 * @array: Array to check
 * @size: Size of the array
 * @head: Head of the list
 *
 * Return: 1 if sorted, 0 if not
 */
int isSorted(int *array, size_t size, listint_t *head)
{
	size_t i;

	if (array)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
				return (0);
		}
		return (1);
	}
	else
	{
		if (head)
		{
			for (; head->next; head = head->next)
			{
				if (head->n > head->next->n)
					return (0);
			}
			return (1);
		}
		return (0);
	}
}

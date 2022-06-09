#include "sort.h"

/**
 * insertion_sort_list - Sorts a linked list of integers in ascending order
 * @list: The list to be sorted
 * Return: The sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *lower, *higher, *next;

	if (!list || !*list)
		return;
	current = (*list)->next;
	for (; current;)
	{
		temp = current, next = current->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			higher = temp->prev, lower = temp;
			if (lower->next)
				lower->next->prev = higher;
			if (higher->prev)
				higher->prev->next = lower;
			higher->next = lower->next;
			lower->prev = higher->prev;
			lower->next = higher;
			higher->prev = lower;
			if (!lower->prev)
				*list = lower;
			print_list(*list);
		}
		current = next;
	}
}

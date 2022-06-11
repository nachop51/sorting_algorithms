#ifndef SORT_H
#define SORT_H

/* Libraries */

#include <stdlib.h>
#include <stdio.h>

/* Linked list struct */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
int isSorted(int *array, size_t size, listint_t *head);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, size_t size, int left, int right);
void swap(int *array, int left, int right);

#endif

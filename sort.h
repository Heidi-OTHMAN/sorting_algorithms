#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* print */
void print_arr(const int *arr, size_t s);
void print_list(const listint_t *list);

void bubble_sort(int *arr, size_t s);
void insertion_sort_list(listint_t **list);
void selection_sort(int *arr, size_t s);
void quick_sort(int *arr, size_t s);
void shell_sort(int *arr, size_t s);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *arr, size_t s);
void radix_sort(int *arr, size_t s);
void counting_sort(int *arr, size_t s);
void heap_sort(int *arr, size_t s);
void bitonic_sort(int *arr, size_t s);
void quick_sort_hoare(int *arr, size_t s);

#endif

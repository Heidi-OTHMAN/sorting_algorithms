#ifndef SORT_H
#define SORT_H

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
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void qs(int *array, ssize_t frst, ssize_t lst, int size);
int lomuto_partition(int *array, ssize_t frst, ssize_t lst, size_t size);
void swap(int *array, ssize_t item_1, ssize_t item_2);
void swapp(int *array, int item_1, int item_2);
listint_t *swap_node(listint_t *node, listint_t **list);
void swaap(listint_t **head, listint_t *node_1, listint_t *node_2);
void *_callooc(unsigned int nmembb, unsigned int size);
void merge(int *array, int *a, int start, int med, int end);
void mergesort(int *array, int *a, int start, int end);

#endif

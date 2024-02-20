#include "sort.h"
/**
  * heap_sort - heap sort algorithm
  * @array: array to sort
  * @size: size of array
  */
void heap_sort(int *array, size_t size)
{
	int l, a;

	for (l = size / 2 - 1; l >= 0; l--)
		heapify(array, l, size, size);
	for (l = size - 1; l >=0; l--)
	{
		a = array[0];
		array[0] = array[l];
		array[l] = a;
		print_array(array, size);
		heapify(array, l, 0, size);
	}
}
void heapify(int *array, int idx, int idx2, size_t size)
{
	int max = idx2;
	int left = 2 * idx2 + 1;
	int right = 2 * idx2 + 2;
	int a;

	if (left < idx && array[left] > array[max])
		max = left;
	if (right < idx && array[right] > array[max])
		max = right;
	if (max != idx2)
	{
		a = array[idx2];
		array[idx2] = array[max];
		array[max] = a;
		print_array(array, size);
		heapify(array, idx, max, size);
	}
}

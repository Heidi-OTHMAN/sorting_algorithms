#include "sort.h"
/**
 * selection_sort- function that sorts using selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t l, m, n;
	int a;

	if (!array || !size)
		return;
	for (l = 0; l < size - 1; l++)
	{
		for (m = size - 1, n = l + 1; m > l; m--)
		{
			if (array[m] < array[n])
			{
				n = m;
			}
		}
		if (array[l] > array[n])
		{
			a = array[l];
			array[l] = array[n];
			array[n] = a;
			print_array(array, size);
		}
	}
}

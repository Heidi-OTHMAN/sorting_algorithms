#include "sort.h"
/**
 * bubble_sort - Function that sorts an array of ints
 * using bubble sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int a;
	size_t l, n;

	if (!array || !size)
		return;

	l = 0;
	while (l < size)
	{
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				a = array[n];
				array[n] = array[n + 1];
				array[n + 1] = a;
				print_array(array, size);
			}
		}
		l++;
	}
}

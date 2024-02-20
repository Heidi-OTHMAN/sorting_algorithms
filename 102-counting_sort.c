#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, n;
	size_t l, m, array_size;

	if (array == NULL || size <= 1)
		return;
	array_size = array[0];
	for (l = 0; array[l]; l++)
	{
		if (array[l] > (int)array_size)
			array_size = array[l];
	}

	array_size += 1;

	count_array = malloc(array_size * sizeof(int *));
	if (count_array == NULL)
		return;

	for (l = 0; l < array_size; l++)
		count_array[l] = 0;

	for (l = 0; l < size; l++)
		count_array[array[l]] += 1;

	for (l = 0; l <= array_size; l++)
		count_array[l] += count_array[l - 1];

	print_array(count_array, array_size);

	for (l = 1, m = 0; l <= array_size; l++)
		if (count_array[l] != count_array[l - 1])
		{
			for (n = 0; n < count_array[l] - count_array[l - 1]; n++)
				array[m++] = l;
		}
	free(count_array);
}

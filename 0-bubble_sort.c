#include "sort.h"
/**
 * bu_sort - Function that sorts an array of ints
 * using bubble sort algorithm
 *
 * @arr: array of ints
 * @s: size of array
 *
 */
void bu_sort(int *arr, size_t s)
{
	int a;
	size_t l, n;

	if (!arr || !s)
		return;

	l = 0;
	while (l < s)
	{
		for (n = 0; n < s - 1; n++)
		{
			if (arr[n] > arr[n + 1])
			{
				a = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = a;
				print_arr(arr, s);
			}
		}
		l++;
	}
}

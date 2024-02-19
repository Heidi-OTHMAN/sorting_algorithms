#include "sort.h"
/**
 * select_sort- function that sorts using selection sort algorithm
 *
 * @arr: array to be sorted
 * @s: size of the array
 *
 */
void select_sort(int *arr, size_t s)
{
	size_t l, m, n;
	int a;

	if (!arr || !s)
		return;
	for (l = 0; l < s - 1; l++)
	{
		for (m = s - 1, n = l + 1; m > l; m--)
		{
			if (arr[m] < arr[n])
			{
				n = m;
			}
		}
		if (arr[l] > arr[n])
		{
			a = arr[l];
			arr[l] = arr[n];
			arr[n] = a;
			print_arr(arr, s);
		}
	}
}

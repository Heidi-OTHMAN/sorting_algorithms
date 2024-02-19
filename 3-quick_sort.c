#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@item_1: array element
*@item_2: array element
*/
void swap(int *array, ssize_t item_1, ssize_t item_2)
{
	int a;

	a = array[item_1];
	array[item_1] = array[item_2];
	array[item_2] = a;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@frst: first array element
 *@lst: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t frst, ssize_t lst, size_t size)
{
	int pivot = array[lst];
	ssize_t current = frst, finder;

	for (finder = frst; finder < lst; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[lst])
	{
		swap(array, current, lst);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@frst: first array element
 *@lst: last array element
 *@size: array size
 */
void qs(int *array, ssize_t frst, ssize_t lst, int size)
{
	ssize_t position = 0;


	if (frst < lst)
	{
		position = lomuto_partition(array, frst, lst, size);

		qs(array, frst, position - 1, size);
		qs(array, position + 1, lst, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

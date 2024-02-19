#include "sort.h"

/**
*swapp - the positions of two elements into an array
*@array: array
*@item_1: array element
*@item_2: array element
*/
void swapp(int *array, int item_1, int item_2)
{

	int a;

	a = array[item_1];
	array[item_1] = array[item_2];
	array[item_2] = a;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gp = 1, l, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (gp < size / 3)
		gp = 3 * gp + 1;
	while (gp >= 1)
	{
		for (l = gp; l < size; l++)
			for (idx = l; idx >= gp &&
			 (array[idx] < array[idx - gp]); idx -= gp)
				swapp(array, idx, idx - gp);
		print_array(array, size);
		gp /= 3;
	}
}

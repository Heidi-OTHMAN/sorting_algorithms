#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *_callooc - this is a calloc function
 *@nmembb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_callooc(unsigned int nmembb, unsigned int size)
{
	unsigned int l = 0;
	char *b;

	if (nmembb == 0 || size == 0)
		return ('\0');
	b = malloc(nmembb * size);
	if (b == '\0')
		return ('\0');
	for (l = 0; l < (nmembb * size); l++)
		b[l] = '\0';
	return (b);
}
/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int inx, maximun = 0, *counter = '\0', *a = '\0';
	size_t i;

	if (array == '\0' || size < 2)
		return;
	/* find maximun number */
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	a = _calloc(size + 1, sizeof(int));
	/* count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	/* get the accumulative values */
	for (inx = 1; inx <= maximun; inx++)
		counter[inx] += counter[inx - 1];
	print_array(counter, maximun + 1);
	/* get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		a[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	/* replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = a[i];
	free(a);
	free(counter);

}

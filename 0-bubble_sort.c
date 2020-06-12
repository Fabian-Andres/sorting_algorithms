#include "sort.h"

/**
 * bubble_sort - Sort in ascending order
 * @array: array of int
 * @size: size of array
 *
 * return: void
*/

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i = 0, j = 0;

	while (j < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			i++;
		}
		j++;
	}
}

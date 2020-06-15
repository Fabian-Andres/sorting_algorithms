#include "sort.h"

/**
 * selection_sort - Sort in ascending order
 * @array: array of int
 * @size: array size
 *
 * return: void
*/

void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0, cambia = 0;

	if (size < 2)
		return;

	for (j = 0; j < size; j++)
	{
		cambia = j;
		i = j + 1;
		while (i < size)
		{
			if (array[i] < array[cambia])
				cambia = i;
			i++;
		}
		if (cambia != j)
		{
			temp = array[cambia];
			array[cambia] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}

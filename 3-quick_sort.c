#include "sort.h"

/**
 * quick_sort - Sort in ascending order
 * @array: array of int
 * @size: array size
 *
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	sorting(array, 0, size - 1, size);
}

/**
 * sorting - recursively call itself
 * @array: array of int
 * @left: start pointer
 * @last: end pointer
 * @size: array size
 *
 * Return: void
*/

void sorting(int *array, int left, int last, size_t size)
{
	int pivot;

	if (left <= last)
	{
		pivot = particion(array, left, last, size);
		sorting(array, left, pivot - 1, size);
		sorting(array, pivot + 1, last, size);
	}
}

/**
 * particion - recursively call itself
 * @array: array of int
 * @left: start pointer
 * @last: end pointer
 * @size: array size
 *
 * Return: Pivot
*/

size_t particion(int *array, int left, int last, size_t size)
{
	int i, j, pivot, temp = 0;

	pivot = array[last];
	i = left - 1;
	/* ordenando la array hasta antes del pivot */
	for (j = left; j < last; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			/* condicional para que no imprima cuando no se cambie de posicion */
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	/* poniendo la posicion del pivot en la array*/
	temp = array[i + 1];
	array[i + 1] = array[last];
	array[last] = temp;
	if (array[last] != array[i + 1])
		print_array(array, size);
	return (i + 1);
}

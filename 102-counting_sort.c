#include "sort.h"

/**
 * counting_sort - function counting sort
 *
 * @array: Pointer of array to sort
 * @size: size of array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int count[10000];
	size_t i = 0, j = 0, aux = 0, max_val = -1;

	if (array == NULL || size == 1)
		return;
	while (i < 10000)
		count[i++] = 0;

	i = 0;
	while (i < size)
	{
		count[array[i]] += 1;
		if (array[i] > (int) max_val)
			max_val = array[i];
		i++;
	}

	i = 1;
	while (i <= max_val)
		i++, count[i] += count[i - 1];

	aux = count[max_val];
	i = max_val + 1;
	while (--i > 0)
		count[i] = count[i - 1];
	count[0] = 0;

	for (i = 0; i < max_val; i++)
	{
		while (count[i] < count[i + 1])
			array[j++] = i, count[i] += 1;
	}

	for (i = aux - count[max_val]; i > 0; i--)
	{
		array[j++] = max_val;
		count[max_val] += 1;
	}

	print_array(count, max_val + 1);
}

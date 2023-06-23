#include "sort.h"

/**
 * counting_sort - sorting an array using Counting sort
 * @array: the array of integers
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *num, *result;
	int a, maximum, tot;

	if (!array || size < 2)
		return;

	maximum = array[0];
	for (a = 0; a < (int)size; a++)
	{
		if (array[a] > maximum)
			maximum = array[a];
	}

	num = calloc((maximum + 1), sizeof(int));
	if (!num)
		return;
	for (a = 0; a < (int)size; a++)
		num[array[a]]++;
	for (a = 0, tot = 0; a < maximum + 1; a++)
	{
		tot = num[a] + tot;
		num[a] = tot;
	}
	print_array(num, maximum + 1);
	result = malloc(sizeof(int) * size);
	if (!result)
		return;
	for (a = 0; a < (int)size; a++)
	{
		result[num[array[a]] - 1] = array[a];
		num[array[a]]--;
	}
	for (a = 0; a < (int)size; a++)
		array[a] = result[a];
	free(num);
	free(result);
}

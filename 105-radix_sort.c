#include "sort.h"

/**
 * count_reset - resetting the bucket count to 0
 * @bucket: array of arrays
 */
void count_reset(int *bucket)
{
	int x;

	for (x = 0; x < 10; x++)
		bucket[x] = 0;
}

/**
 * btk_create - allocating memory for arrays in buckets
 * @b: array of members
 * @count: size of the array members
 */
void btk_create(int **b, int *count)
{
	int x;
	int *crate;

	for (x = 0; x < 10; x++)
	{
		crate = malloc(sizeof(int) * count[x]);
		if (!crate)
		{
			for (; x > -1; x--)
				free(b[x]);
			free(b);
			exit(EXIT_FAILURE);
		}
		b[x] = crate;
	}
	count_reset(count);
}

/**
 * max_get - find array of integers with biggest value
 * @list: the array of values
 * @size: the size of the array
 * Return: biggest value
 */
int max_get(int *list, size_t size)
{
	size_t x;
	int biggest;

	biggest = list[0];
	for (x = 1; x < size; x++)
		if (list[x] > biggest)
			biggest = list[x];
	return (biggest);
}
/**
 * push_list - function to flatten bucket into sorted array by digit
 * @list: values printed
 * @size: the size of the array
 * @b: the buckets
 * @count: the number of buckets
 */
void push_list(int *list, size_t size, int **b, int *count)
{
	int x, y, z;

	for (z = 0, x = 0; z < 10; z++)
	{
		for (y = 0; y < count[z]; y++, x++)
			list[x] = b[z][y];
	}
	print_array(list, size);
	for (x = 0; x < 10; x++)
		free(b[x]);
}

/**
 * radix_sort - sorting an array of integers using Radix sort
 * @array: the array of integers
 * @size: the size of the integers
 */
void radix_sort(int *array, size_t size)
{
	int count[10];
	int **b;
	int maximum, largest, p, d, number;
	size_t j;

	if (!array || size < 2)
		return;
	b = malloc(sizeof(int *) * 10);
	if (!b)
		exit(1);
	maximum = max_get(array, size);
	for (largest = 0; maximum > 0; largest++)
		maximum /= 10;
	for (p = 0, d = 1; p < largest; p++, d *= 10)
	{
		count_reset(count);
		for (j = 0; j < size; j++)
		{
			number = (array[j] / d) % 10;
			count[number]++;
		}
		btk_create(b, count);
		for (j = 0; j < size; j++)
		{
			number = (array[j] / d) % 10;
			b[number][count[number]] = array[j];
			count[number]++;
		}
		push_list(array, size, b, count);
	}
	free(b);
}

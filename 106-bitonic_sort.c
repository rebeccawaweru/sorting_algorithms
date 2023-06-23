#include "sort.h"
/**
 * compare - sorting contents of current array
 * @asc: sort in ascending order
 * @sub: subarray in the frame
 * @size: the size of array
 */
void compare(bool asc, int *sub, size_t size)
{
	int current;
	size_t j, d;

	d = size / 2;
	for (j = 0; j < d; j++)
	{
		if ((sub[j] > sub[j + d]) == asc)
		{
			current = sub[j];
			sub[j] = sub[j + d];
			sub[j + d] = current;
		}
	}
}
/**
 * merge - merging sorted results
 * @asc: ascending order
 * @sub: subarray
 * @size: size of the array
 * @initial: intial index of the subarray within the source array
 */
void merge(bool asc, int *sub, size_t size, size_t initial)
{
	int *pre, *post;

	if (size > 1)
	{
		pre = sub;
		post = sub + (size / 2);
		compare(asc, sub, size);
		merge(asc, pre, size / 2, initial);
		merge(asc, post, size / 2, initial);
	}
}

/**
 * rec_sort - recursive engine of Bitonic sort
 * @asc: ascending order if true
 * @sub: the subarray
 * @size: the size of the array
 * @initial: the array being sourced
 */
void rec_sort(bool asc, int *sub, size_t size, size_t initial)
{
	int *pre, *post;

	if (size <= 1)
		return;
	pre = sub;
	post = sub + (size / 2);
	printf("Merging [%lu/%lu] (%s):\n", size, initial,
		(asc ? "UP" : "DOWN"));
	print_array(sub, size);
	rec_sort(true, pre, size / 2, initial);
	rec_sort(false, post, size / 2, initial);
	merge(asc, pre, size, initial);
	printf("Result [%lu/%lu] (%s):\n", size, initial,
		(asc ? "UP" : "DOWN"));
	print_array(sub, size);
}

/**
 * bitonic_sort - sort array of integers using Bitonic sort
 * @array: the array of integers
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	rec_sort(true, array, size, size);
}

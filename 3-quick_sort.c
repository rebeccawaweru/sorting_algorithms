#include "sort.h"

/**
 * scan - check for values less than pivot value and swaps them
 * @listt: list of integers
 * @start: beginning of the partition
 * @end: end of the partition
 * @size: size of array
 * Return: index
 */
int scan(int *listt, int start, int end, size_t size)
{
	int x, y, pvt, current;

	pvt = listt[end];
	x = start;
	for (y = start; y < end; y++)
	{
		if (listt[y] < pvt)
		{
			current = listt[x];
			listt[x] = listt[y];
			listt[y] = current;
			if (listt[x] != listt[y])
				print_array(listt, size);
			x++;
		}
	}
	current = listt[x];
	listt[x] = listt[end];
	listt[end] = current;
	if (listt[x] != listt[end])
		print_array(listt, size);
	return (x);
}
/**
 * rec_sort - sorting an array by separating into partitions
 * @listt: integers to be sorted
 * @start: start of partition
 * @end: end of partition
 * @size: size of the array
 */
void rec_sort(int *listt, int start, int end, size_t size)
{
	int a;

	if (start < end)
	{
		a = scan(listt, start, end, size);
		rec_sort(listt, start, a - 1, size);
		rec_sort(listt, a + 1, end, size);
	}
}
/**
 * quick_sort - use Quick sort to sort array in ascending order
 * @array: the array of integer
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rec_sort(array, 0, (int)size - 1, size);
}

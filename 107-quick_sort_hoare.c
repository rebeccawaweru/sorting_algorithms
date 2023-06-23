#include "sort.h"

/**
 * divide - use of rightmost index as pivot
 * @list: the list of array
 * @start: index that starts the petition
 * @end: index that ends the petition
 * @size: the size of the array
 * Return: the index after partitioning
 */
int divide(int *list, size_t start, size_t end, size_t size)
{
	int x, y, pvt, current;

	pvt = list[end];
	x = start - 1;
	y = end + 1;
	while (true)
	{
		do {
			x++;
		} while (list[x] < pvt);
		do {
			y--;
		} while (list[y] > pvt);
		if (x == y)
			return (y - 1);
		else if (x > y)
			return (y);
		current = list[x];
		list[x] = list[y];
		list[y] = current;
		print_array(list, size);
	}
}

/**
 * sortquick - sorting array by separating into divisions/partitions
 * @list: the list of integers
 * @start: the index that starts the petition
 * @end: the index that ends the petition
 * @size: the size of the list
 */
void sortquick(int *list, size_t start, size_t end, size_t size)
{
	size_t next;

	if (start < end)
	{
		next = divide(list, start, end, size);
		sortquick(list, start, next, size);
		sortquick(list, next + 1, end, size);
	}
}

/**
 * quick_sort_hoare - sorts array using Quick sort
 * @array: the array being sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sortquick(array, 0, size - 1, size);
}

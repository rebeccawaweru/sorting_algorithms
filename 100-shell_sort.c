#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using Shell sort
 * @array: array of integers
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int x, y, space, num, maximum, current;

	if (!array || size < 2)
		return;
	num = (int)size;
	for (space = 1; space < num; space = (space * 3) + 1)
	{
		maximum = space;
	}
	for (space = maximum; space > 0; space = (space - 1) / 3)
	{
		for (x = space; x < num; x++)
		{
			current = array[x];
			for (y = x; y >= space && array[y - space] > current; y -= space)
			{
				array[y] = array[y - space];
			}
			array[y] = current;
		}
		print_array(array, size);
	}
}

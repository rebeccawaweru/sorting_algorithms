#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int current;
	bool changed = true;
	size_t x, y;

	if (!array || size < 2)
		return;

	y = size;
	while (changed)
	{
		changed = false;
		for (x = 1; x < y; x++)
		{
			if (array[x - 1] > array[x])
			{
				current = array[x - 1];
				array[x - 1] = array[x];
				array[x] = current;
				changed = true;
				print_array(array, size);
			}
		}
		y--;
	}
}

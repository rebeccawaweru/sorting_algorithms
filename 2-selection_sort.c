#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: an array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int x, y, least, current, num = (int)size;

	if (!array || size < 2)
		return;
	for (x = 0; x < num - 1; x++)
	{
		least = x;
		for (y = x + 1; y < num; y++)
		{
			if (array[y] < array[least])
				least = y;
		}
		if (least != x)
		{
			current = array[x];
			array[x] = array[least];
			array[least] = current;
			print_array(array, size);
		}
	}

}

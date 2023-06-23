#include "sort.h"

void shuffle_down(int *list, size_t size, int pre, int post);
/**
 * p_node - get parent index
 * @start: the first index
 * Return: parent index
 */
int p_node(int start)
{
	return ((start - 1) / 2);
}

/**
 * left_node - get the index of left child
 * @start: the first index
 * Return: the index of the left child
 */
int left_node(int start)
{
	return ((2 * start) + 1);
}
/**
 * heap_conv - convert arrays into heap
 * @list: array of integers
 * @size: the size of the list
 */
void heap_conv(int *list, size_t size)
{
	int begin;

	begin = p_node(size - 1);

	while (begin >= 0)
	{
		shuffle_down(list, size, begin, size - 1);
		begin--;
	}
}
/**
 * shuffle_down - shuffle into ascending order
 * @list: the array beig sorted
 * @size: size of the list
 * @pre: the first index
 * @post: the last index
 */
void shuffle_down(int *list, size_t size, int pre, int post)
{
	int rise, change, current, offspring;

	rise = pre;
	while (left_node(rise) <= post)
	{
		offspring = left_node(rise);
		change = rise;

		if (list[change] < list[offspring])
			change = offspring;
		if (offspring + 1 <= post && list[change] < list[offspring + 1])
			change = offspring + 1;
		if (change != rise)
		{
			current = list[rise];
			list[rise] = list[change];
			list[change] = current;
			print_array(list, size);
			rise = change;
		} else
			return;
	}
}

/**
 * heap_sort - sort array using Heap Sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int post, current;

	if (!array || size < 2)
		return;
	heap_conv(array, size);

	post = (int)size - 1;
	while (post > 0)
	{
		current = array[post];
		array[post] = array[0];
		array[0] = current;
		print_array(array, size);
		post--;
		shuffle_down(array, size, 0, post);
	}
}

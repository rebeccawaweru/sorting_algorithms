#include "sort.h"

/**
 * get_arry - print range indicies
 * @list: list of values
 * @pre: first index
 * @post: last index
 */
void get_arry(int *list, int pre, int post)
{
	int x;

	for (x = pre; x < post; x++)
	{
		if (x < post - 1)
			printf("%x, ", list[x]);
		else
			printf("%x\n", list[x]);
	}
}

/**
 * cpy - copying function
 * @s: the source
 * @pre: first index
 * @post: last index
 * @dst: the destination
 */
void cpy(int *s, int pre, int post, int *dst)
{
	int x;

	for (x = pre; x < post; x++)
		dst[x] = s[x];
}
/**
 * TopDownMerge - sort the source in ascending oreder
 * @s: the source
 * @pre: the left start index
 * @mid: the right start index
 * @post: the last index
 * @dst: the destination
 */
void TopDownMerge(int *s, int pre, int mid, int post, int *dst)
{
	int x, y, z;

	x = pre, y = mid;

	printf("Merging...\n");
	printf("[left]: ");
	get_arry(s, pre, mid);
	printf("[right]: ");
	get_arry(s, mid, post);

	for (z = pre; z < post; z++)
	{
		if (x < mid && (y >= post || s[x] <= s[y]))
		{
			dst[z] = s[x];
			x++;
		} else
		{
			dst[z] = s[y];
			y++;
		}
	}
	printf("[Done]: ");
	get_arry(dst, pre, post);
}
/**
 * TopDownSplitMerge - spliting working copies
 * @s: the source
 * @pre: the first index
 * @post: the last index
 * @dst: the destination
 */
void TopDownSplitMerge(int *s, int pre, int post, int *dst)
{
	int center;

	if (post - pre < 2)
		return;
	center = (post + pre) / 2;

	TopDownSplitMerge(dst, pre, center, s);
	TopDownSplitMerge(dst, center, post, s);

	TopDownMerge(s, pre, center, post, dst);
}

/**
 * merge_sort - use Merge sort to sort array of integers in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *present;

	if (!array || size < 2)
		return;
	present = malloc(sizeof(int) * size);
	if (!present)
		return;
	cpy(array, 0, size, present);
	TopDownSplitMerge(present, 0, size, array);

	free(present);
}

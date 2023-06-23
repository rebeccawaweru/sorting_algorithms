#include "sort.h"
/**
 * swap_adjacent - swapping of adjacent nodes in a doubly linked list
 * @array: list of integers
 * @head: node close to the head
 * @tail: node cloase to the tail
 */
void swap_adjacent(listint_t **array, listint_t *head, listint_t *tail)
{
	listint_t *change;

	if (head->prev)
		head->prev->next = tail;
	else
		*array = tail;
	if (tail->next)
		tail->next->prev = head;
	tail->prev = head->prev;
	head->prev = tail;
	change = tail;
	head->next = tail->next;
	change->next = head;
	print_list(*array);
}

/**
 * cocktail_sort_list - use Cocktail shaker sort in
 * doubly linked list of integers
 * @list: the list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int count = 1000000, counters;
	listint_t *current;
	bool x_changed, y_changed;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = *list;
	do {
		x_changed = y_changed = false;
		for (counters = 0; current->next && counters < count; counters++)
		{
			if (current->next->n < current->n)
			{
				swap_adjacent(list, current, current->next);
				x_changed = true;
			}
			else
				current = current->next;
		}
		if (!current->next)
			count = counters;
		if (x_changed)
			current = current->prev;
		count--;
		for (counters = 0; current->prev && counters < count; counters++)
		{
			if (current->n < current->prev->n)
			{
				swap_adjacent(list, current->prev, current);
				y_changed = true;
			}
			else
				current = current->prev;
		}
		if (y_changed)
			current = current->next;
	} while (x_changed || y_changed);
}

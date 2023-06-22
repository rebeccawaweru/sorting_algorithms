#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * @list: list to be printed i.e doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *start, *nxt, *fresh, *current;

	if (!list || !(*list) || !((*list)->next))
		return;
	nxt = (*list);
	start = (*list)->next;
	while (start)
	{
		fresh = start->next;
		while (nxt && start->n < nxt->n)
		{
			if (nxt->prev)
				nxt->prev->next = start;
			else
				*list = start;
			if (start->next)
				start->next->prev = nxt;
			current = start->next;
			start->next = nxt;
			start->prev = nxt->prev;
			nxt->next = current;
			nxt->prev = start;
			print_list(*list);
			nxt = start->prev;
		}
		start = fresh;
		if (start)
			nxt = start->prev;
	}
}

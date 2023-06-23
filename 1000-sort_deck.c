#include "deck.h"

/**
 * compare_string - function to compare two strings
 * @string1: the first string
 * @string2: the second string
 * Return: 1 if equal else 0
 */
int compare_string(const char *string1, char *string2)
{
	size_t j = 0;

	if (*string1 == '\0')
		return (0);
	while (string1[j])
	{
		if (string1[j] != string2[j])
			return (0);
		j++;
	}
	if (string1[j] == '\0' && string2[j])
		return (0);
	return (1);
}
/**
 * pos_card - get the position of the card
 * @knob: the card
 * Return: position of the card
 */
int pos_card(deck_node_t *knob)
{
	int entity;

	entity = (*knob).card->value[0] - '0';
	if (entity < 50 || entity > 57)
	{
		if (compare_string((*knob).card->value, "Ace") == 1)
			entity = 1;
		else if (compare_string((*knob).card->value, "10") == 1)
			entity = 10;
		else if (compare_string((*knob).card->value, "Jack") == 1)
			entity = 11;
		else if (compare_string((*knob).card->value, "Queen") == 1)
			entity = 12;
		else if (compare_string((*knob).card->value, "King") == 1)
			entity = 13;
	}
	entity += (*knob).card->kind * 13;
	return (entity);
}
/**
 * c_turn - change card to the previous one
 * @c: the card
 * @d: the deck of cards
 * Return: pointer of a card
 */
deck_node_t *c_turn(deck_node_t *c, deck_node_t **d)
{
	deck_node_t *b = c->prev, *present = c;

	b->next = present->next;
	if (present->next)
		present->next->prev = b;
	present->next = b;
	present->prev = b->prev;
	b->prev = present;
	if (present->prev)
		present->prev->next = present;
	else
		*d = present;
	return (present);
}
/**
 * insert - sorts a doubly linked list in ascending order using Insertion
 * @d: the deck of cards
 */
void insert(deck_node_t **d)
{
	deck_node_t *knob;
	int prev, current;

	if (d == NULL || (*d)->next == NULL)
		return;
	knob = (*d)->next;
	while (knob)
	{
		if (knob->prev)
		{
			prev = pos_card((knob->prev));
			current = pos_card(knob);
		}
		while ((knob->prev) && (prev > current))
		{
			prev = pos_card((knob->prev));
			current = pos_card(knob);
			knob = c_turn(knob, d);
		}
		knob = knob->next;
	}
}
/**
 * sort_deck - a function that sorts out a deck of cards
 * @deck: the deck of cards being sorted
 */
void sort_deck(deck_node_t **deck)
{
	insert(deck);
}

#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @g: address of first node
 * @h: address of second node
 *
 * Return: void
 */
void swap(listint_t *g, listint_t *h)
{
	if (g->prev)
		g->prev->next = h;
	if (h->next)
		h->next->prev = g;
	g->next = h->next;
	h->prev = g->prev;
	g->prev = h;
	h->next = g;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *l, *m;

	if (!list || !*list || !(*list)->next)
		return;
	l = (*list)->next;
	while (l)
	{
		m = l;
		l = l->next;
		while (m && m->prev)
		{
			if (m->prev->n > m->n)
			{
				swap(m->prev, m);
				if (!m->prev)
					*list = m;
				print_list((const listint_t *)*list);
			}
			else
				m = m->prev;
		}
	}
}

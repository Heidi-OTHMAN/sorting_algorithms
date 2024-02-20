#include "sort.h"

/**
 * swaap - swaps two nodes
 * @head: head of the list
 * @node1: first node to sort
 * @node2: second node to sort
 */
void swaap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flaag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swaap(list, head, head->next);
				print_list(*list);
				flaag = 1;
				head = head->prev;
			}
		}
		if (flaag == 0)
			break;
		flaag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap(list, head->prev, head);
				print_list(*list);
				flaag = 1;
				head = head->next;
			}
		}
	} while (flaag == 1);
}

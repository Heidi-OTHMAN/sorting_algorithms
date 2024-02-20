#include "sort.h"

/**
 * swaap - swaps two nodes
 * @head: head of the list
 * @node_1: first node to sort
 * @node_2: second node to sort
 */
void swaap(listint_t **head, listint_t *node_1, listint_t *node_2)
{
	listint_t *prev, *next;

	prev = node_1->prev;
	next = node_2->next;

	if (prev != NULL)
		prev->next = node_2;
	else
		*head = node_2;
	node_1->prev = node_2;
	node_1->next = next;
	node_2->prev = prev;
	node_2->next = node_1;
	if (next)
		next->prev = node_1;
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
				swaap(list, head->prev, head);
				print_list(*list);
				flaag = 1;
				head = head->next;
			}
		}
	} while (flaag == 1);
}

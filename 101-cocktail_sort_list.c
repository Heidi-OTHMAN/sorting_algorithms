#include "sort.h"
#include <stdio.h>
/**
 *swapp_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swapp_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *curnt = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = curnt->next;
	if (curnt->next)
		curnt->next->prev = back;
	curnt->next = back;
	curnt->prev = back->prev;
	back->prev = curnt;
	if (curnt->prev)
		curnt->prev->next = curnt;
	else
		*list = curnt;
	return (curnt);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swapp_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swapp_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}

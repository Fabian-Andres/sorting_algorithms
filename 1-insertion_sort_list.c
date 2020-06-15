#include "sort.h"
/**
 * insertion_sort_list - Function to sort doubly linked list
 * @list: list node
 *
 * return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node_c = NULL, *node_p = NULL, *node_aux = NULL;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;
	node_c = *list;
	while (node_c != NULL)
	{
		node_p = node_c;
		while (node_p->prev != NULL)
		{
			if (node_p->prev->n > node_p->n)
			{
				if (node_p->prev->prev != NULL)
					node_p->prev->prev->next = node_p;
				else
					*list = node_p;

				if (node_p->next != NULL)
					node_p->next->prev = node_p->prev;

				node_aux = node_p->prev->prev;

				node_p->prev->next = node_p->next;
				node_p->prev->prev = node_p;

				node_p->next = node_p->prev;
				node_p->prev = node_aux;

				print_list(*list);
			}
			else
				break;
		}
		node_c = node_c->next;
	}
}

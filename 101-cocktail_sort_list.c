#include "sort.h"

/**
 * cocktail_sort_list - Order function whit cocktail sort algoritm
 * @list: Pointer to bouble linked list
 *
 * Return: void
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *node_c = NULL;
	int sorted = 0;

	if (list == NULL || *list == NULL)
		return;
	node_c = *list;
	while (sorted == 0)
	{
		sorted = 1;
		while (node_c->next != NULL)
		{
			if ((node_c->n) > (node_c->next)->n)
			{
				sort_nodes(node_c);
				while ((*list)->prev != NULL)
					*list = (*list)->prev;
				print_list(*list), sorted = 0;
				node_c = node_c->prev;
			}
			if (node_c->next != NULL)
				node_c = node_c->next;
		}

		if (sorted == 0)
		{
			while (node_c->prev != NULL)
			{
				if ((node_c->prev)->n > node_c->n)
				{
					sort_nodes(node_c->prev);
					while ((*list)->prev != NULL)
						*list = (*list)->prev;
					print_list(*list), sorted = 0;
					node_c = node_c->next;
				}
				if (node_c->prev != NULL)
					node_c = node_c->prev;
			}
		}
	}
}

/**
 * sort_nodes - Ordering positions
 * @list: Pointer to bouble linked list
 *
 * Return: int
*/

int sort_nodes(listint_t *list)
{
	listint_t *node_c = NULL, *node_p = NULL, *node_aux = NULL;

	if (list == NULL)
		return (0);
	if (list->next == NULL)
		return (0);

	node_c = list;
	node_p = list->next;

	node_aux = node_p->next;
	node_p->next = node_c;
	node_p->prev = node_c->prev;
	node_c->next = node_aux;
	node_c->prev = node_p;

	if (node_p->prev != NULL)
		(node_p->prev)->next = node_p;
	if (node_c->next != NULL)
		(node_c->next)->prev = node_c;

	return (1);
}

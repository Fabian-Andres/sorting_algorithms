#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *b = NULL, *a = NULL;
    // , *temp_aux = NULL

    b = *list;
    while (b != NULL)
    {
        a = b->prev;
        while (a != NULL && a->n > b->n)
        {
            // temp_aux = b->next;
            // b->next = a;
            // b->prev = a->prev;
            // a->next = temp_aux;
            // a->prev = b;
            printf("prev %d next %d\n", a->n, b->n);

            a = a->prev;
        }
        print_list(*list);

        b = b->next;
    }
}

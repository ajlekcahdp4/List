#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int ListCtor (List* lst)
{
    lst->capacity = 16;
    lst->data = calloc (lst->capacity, sizeof (list_t));
    lst->next = calloc (lst->capacity, sizeof (int));
    lst->prev = calloc (lst->capacity, sizeof (int));
    lst->free = 1;
    lst->head = 1;
    lst->tail = 1;

    for (int i = 1; i < lst->capacity; i++)
    {
        lst->next[i] = -i - 1;
    }
    return 0;
}


int ListInsert (List* lst, int last, list_t val)
{
    lst->next[lst->free] = lst->next[last];
    lst->next[last] = lst->free;
    lst->data[lst->free] = val;
    return 0;
}

int ListDtor (List* lst)
{
    free (lst->data);
    free (lst->next);
    free (lst->prev);
    free (lst);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "graphdump/Dump.h"


int ListCtor (List* lst)
{
    system ("mkdir temp");
    lst->capacity = 8;
    lst->data = calloc (lst->capacity, sizeof (list_t));
    lst->next = calloc (lst->capacity, sizeof (int));
    lst->prev = calloc (lst->capacity, sizeof (int));
    lst->free = 1;
    lst->head = 0;
    lst->tail = 0;

    for (int i = 1; i < lst->capacity - 1; i++)
    {
        lst->next[i] = -i - 1;
        lst->prev[i] = -1;
    }
    lst->prev[lst->capacity - 1] = -1;
    return 0;
}


int ListInsert (List* lst, int last, list_t val)
{
    int free = lst->free;
    lst->data[free] = val;
    lst->free = fabs(lst->next[lst->free]);
    if (lst->size == 0)
    {
        lst->next[free] = 0;
        lst->prev[free] = 0;
        lst->head = free;
    }
    else
    {
        lst->next[free] = lst->next[last];
        lst->next[last] = free;
        lst->prev[free] = last;
    }


    if (last == lst->tail)
        lst->tail = free;
    lst->size += 1;

    return 0;
}

int ListDelete (List* lst, int to_del) //rewrite
{
    int prev = lst->prev[to_del];
    if (to_del == lst->head)
        lst->head = lst->next[lst->head];
    lst->size -= 1;

    lst->next[prev] = lst->next[to_del];
    lst->prev[lst->next[to_del]] = prev;
    lst->next[to_del] = -lst->free;
    lst->free = to_del;
    return 0;
}    

void ListResize (List* lst, int new_capacity)
{
    lst->data = realloc (lst->data, new_capacity*sizeof(list_t));
    lst->next = realloc (lst->next, new_capacity*sizeof(int));
    lst->prev = realloc (lst->prev, new_capacity*sizeof(int));
    //===================insertes=to=the=free=list====================
    for (int i = lst->tail + 1; i < new_capacity; i++)
    {
        lst->next[i] = -lst->free;
        lst->free = i;

        lst->prev[i] = -1;
    }
    //===================end===========================================

    lst->capacity = new_capacity;
}

int ListDump (List* lst)
{
    FILE* dotfile = fopen ("temp/dump.dot", "w");
    DtStart (dotfile);
    DtSetTitle (dotfile, lst);
    int cur = lst->head;
    while (cur != 0)
    {
        DtSetNode (dotfile, lst, cur);
        cur = lst->next[cur];
    }
    fprintf (dotfile, "\n\n\n");

    DtSetDependence (dotfile, lst);
    DtEnd (dotfile);
    fclose(dotfile);
    system("dot temp/dump.dot -T png -o dump.png");
    return 0;
}

int ListDtor (List* lst)
{
    system ("rm -rf temp/");
    free (lst->data);
    free (lst->next);
    free (lst->prev);
    free (lst);
    return 0;
}
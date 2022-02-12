#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "graphdump/Dump.h"


int ListCtor (List* lst, char* log_file_name)
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
    }
    else
    {
        lst->next[free] = lst->next[last];
        lst->next[last] = free;
        lst->prev[free] = last;
    }
    lst->tail += 1;
    lst->size += 1;
    
    return 0;
}

int ListDelete (List* lst, int to_del)
{
    int prev = lst->prev[to_del];
    lst->next[prev] = lst->next[to_del];
    lst->prev[lst->next[to_del]] = prev;
    lst->next[to_del] = -lst->free;
    lst->free = to_del;
}

int ListDump (List* lst)
{
    FILE* dotfile = fopen ("temp/dump.dot", "w");
    DtStart (dotfile);
    int i = 0;
    for (i = 1; i <= lst->size; i++)
    {
        DtSetNode (dotfile, lst, i);
    }
    DtSetDependence (dotfile, i - 1);
    DtEnd (dotfile);
    fclose(dotfile);
    system("dot temp/dump.dot -T png -o dump.png");
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
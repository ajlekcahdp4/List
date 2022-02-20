#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "graphdump/Dump.h"


List* ListCtor (int capacity)
{
    List* lst = 0;
    lst = calloc (1, sizeof (List));
    lst->capacity   = capacity;
    lst->size       = 0;
    lst->free       = 1;
    lst->fic        = 0;
    lst->linearized = 1;
    lst->data = calloc (lst->capacity, sizeof (list_t));
    lst->next = calloc (lst->capacity, sizeof (int));
    lst->prev = calloc (lst->capacity, sizeof (int));
    lst->next[lst->fic] = lst->fic;
    lst->prev[lst->fic] = lst->fic;

    for (int i = 1; i < lst->capacity - 1; i++)
    {
        lst->next[i] = -i - 1;
        lst->prev[i] = -1;
    }
    lst->prev[lst->capacity - 1] = -1;
    return lst;
}


int ListInsertAft (List* lst, int last, list_t val)
{
    if (lst == 0)
        return -1;

    if (lst->next[last] != lst->prev[lst->fic])
        lst->linearized = 0;
    
    if (lst->size == lst->capacity - 1)
        ListResize (lst, lst->capacity * 2);
    
    int free = lst->free;
    lst->data[free] = val;
    lst->free = fabs(lst->next[lst->free]);

    //=============================insertion===============================
    lst->next[free] = lst->next[last];
    lst->next[last] = free;
    lst->prev[free] = last;
    lst->prev[lst->next[free]] = free;
    //=========================end=of=insertion============================
    lst->size += 1;

    return free;
}

int ListDelete (List* lst, int to_del)
{
    int prev = lst->prev[to_del];
    
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
    //===================insertes=to=the=free's=list==================
    for (int i = lst->capacity; i < new_capacity; i++)
    {
        lst->next[i] = -lst->free;
        lst->free = i;

        lst->prev[i] = -1;

        lst->data[i] = 0;
    }
    //===================end===========================================

    lst->capacity = new_capacity;
}

List* Linearization  (List* lst)
{
    List* new_lst  = ListCtor (lst->capacity);

    int phys_n = 0;
    int last_pos = new_lst->fic;
    for (int i= 1; i <= lst->size; i++)
    {
        phys_n = VerySlowDoNotCallMeLogicalToPhysical (lst, i);
        last_pos = ListInsertAft (new_lst, last_pos, lst->data[phys_n]);
    }
    ListDtor (lst);
    return new_lst;
}

int  VerySlowDoNotCallMeLogicalToPhysical (List* lst, int log_num)
{
    int cur = lst->fic;

    for (int i = 0; i < log_num; i++)
        cur = lst->next[cur];
    return cur;
}



int ListDump (List* lst)
{
    system ("mkdir temp");
    FILE* dotfile = fopen ("temp/dump.dot", "w");

    DtStart (dotfile);
    DtSetTitle (dotfile, lst);
    int cur = lst->next[lst->fic];
    while (cur != lst->fic)
    {
        DtSetNode (dotfile, lst, cur);
        cur = lst->next[cur];
    }
    fprintf (dotfile, "\n\n\n");

    DtSetDependence (dotfile, lst);
    DtEnd (dotfile);
    fclose(dotfile);
    system("dot temp/dump.dot -T png -o dump.png");
    system ("rm -rf temp/");
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
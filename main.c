#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List* lst = calloc (1, sizeof(List));

    ListCtor (lst);
    ListInsert(lst, lst->tail, 1);
    ListInsert(lst, lst->tail, 2);
    ListInsert (lst, lst->tail, 3);
    ListInsert (lst, lst->tail, 4);
    ListInsert (lst, lst->tail, 5);
    ListInsert (lst, lst->tail, 6);
    ListResize (lst, 16);
    ListInsert (lst, lst->tail, 66);
    ListDelete (lst, 3);
    ListInsert (lst, 2, 7);

    ListDump (lst);
    ListDtor(lst);
    return 0;
}
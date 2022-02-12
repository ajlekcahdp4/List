#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List* lst = calloc (1, sizeof(List));

    ListCtor (lst, "first_log.txt");
    ListInsert(lst, lst->head, 1);
    ListInsert(lst, lst->tail, 2);
    ListDump (lst);
    ListDtor(lst);
    return 0;
}
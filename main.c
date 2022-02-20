#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List* lst = calloc (1, sizeof(List));

    ListCtor (lst);

    int last_elem = ListInsertAft(lst, lst->fic, 1);
    
    
    last_elem = ListInsertAft(lst, last_elem, 2);
    /*ListInsertAft (lst, lst->tail, 3);
    ListInsertAft (lst, lst->tail, 4);
    ListInsertAft (lst, lst->tail, 5);
    ListInsertAft (lst, lst->tail, 6);
    ListResize (lst, 16);
    ListInsertAft (lst, lst->tail, 66);
    ListDelete (lst, 3);
    ListInsertAft (lst, 2, 7);
    */
    ListDump (lst);
    ListDtor(lst);
    return 0;
}
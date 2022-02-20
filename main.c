#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main ()
{
    List* lst = calloc (1, sizeof(List));


    ListCtor (lst);

    int last_elem = ListInsertAft(lst, lst->fic, 1);
    
    for (int i = 2; i < 20; i++)
        last_elem = ListInsertAft(lst, last_elem, i);
    
    ListDump (lst);
    ListDtor(lst);
    return 0;
}
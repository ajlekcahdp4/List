#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main ()
{
    List* lst = calloc (1, sizeof(List));

    
    ListCtor (lst);
    ListInsert(lst, lst->head, 1);
    
    ListDtor(lst);
    return 0;
}
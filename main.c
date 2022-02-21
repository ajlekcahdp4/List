#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main ()
{


    List* lst = 0;
    lst = ListCtor (8);

    int last_elem = ListInsertAft(lst, lst->fic, 1);
    
    for (int i = 2; i < 20; i++)
        last_elem = ListInsertAft(lst, last_elem, i);
    lst = Linearization (lst);
    
    ListGraphDump (lst, "dump.svg");
    ListDtor(lst);
    return 0;
}
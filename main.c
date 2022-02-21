#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main ()
{


    List* lst = 0;
    lst = ListCtor (8, "logs/log.html");

    int last_elem = ListInsertAft(lst, lst->fic, 1);
    
    for (int i = 2; i < 20; i++)
        last_elem = ListInsertAft(lst, last_elem, i);
    ListGraphDump (lst, "dump1.svg");
    lst = Linearization (lst);
    
    ListGraphDump (lst, "dump2.svg");
    last_elem = ListInsertAft(lst, lst->prev[lst->fic], 1);
    ListGraphDump (lst, "dump3.svg");
    ListDtor(lst);
    return 0;
}
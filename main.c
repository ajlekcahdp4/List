#include <stdio.h>
#include "list.h" // including the list


int main ()
{
    List* lst = 0;
    lst = ListCtor (2, "logs/log.html"); // Create a list structure

    long long last_elem = ListInsertAft(lst, lst->fic, 1); // Insert first node and save it's index returns
    
    for (int i = 2; i < 10; i++)
        last_elem = ListInsertAft(lst, last_elem, i); // Insert several nodes in a loop

    ListGraphDump (lst, "dump1.svg"); // Dump our list

    lst = Linearization (lst); // There we understand, that we don't need speed any more and linearixed our list for most useful usege
    ListInsertAft(lst, 6, 10); // Insert node with data 10 after 6's node

    ListGraphDump (lst, "dump2.svg"); // One more dump
    ListDtor(lst); // Destructing our list
    return 0;
}
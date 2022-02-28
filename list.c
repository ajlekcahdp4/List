#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "list.h"
#include "dump/dump.h"
#include "graphdump/DtDump.h"

void ListCheck (List* lst);




List* ListCtor (size_t capacity, char* logfile_name)
{
    List* lst = 0;
    lst = calloc (1, sizeof (List));

    lst->capacity   = capacity;
    lst->size       = 0;
    lst->free       = 1;
    lst->fic        = 0;
    lst->linearized = 1;

    lst->data = calloc (lst->capacity, sizeof (list_t));
    lst->next = calloc (lst->capacity, sizeof (long long));
    lst->prev = calloc (lst->capacity, sizeof (long long));
    
    lst->next[lst->fic] = lst->fic;
    lst->prev[lst->fic] = lst->fic;
    
    for (int i = 1; (unsigned)i < lst->capacity - 1; i++)
    {
        lst->next[i] = -i - 1;
        lst->prev[i] = -1;
    }

    lst->prev[lst->capacity - 1] = -1;
    lst->logfile = HtmlStart (logfile_name);
    return lst;
}


long long ListInsertAft (List* lst, long long last, list_t val)
{
    ListCheck (lst);
    if (lst == 0)
        return -1;
    if (lst->size == lst->capacity - 1)
        ListResize (lst, lst->capacity * 2);
    
    long long int free = lst->free;
    if (free != lst->prev[lst->fic] + 1)
        lst->linearized = 0;
    lst->data[free] = val;
    lst->free = llabs(lst->next[lst->free]);

    //=============================insertion===============================
    lst->next[free] = lst->next[last];
    lst->next[last] = free;
    lst->prev[free] = last;
    lst->prev[lst->next[free]] = free;
    //=========================end=of=insertion============================
    lst->size += 1;
    

    return free;
}

void ListDelete (List* lst, long long to_del)
{
    ListCheck (lst);
    if (lst->size == 0)
        PrintError (lst->logfile, ERR_LIST_UNDERFLOW);


    long long prev = lst->prev[to_del];
    lst->size -= 1;
    lst->next[prev] = lst->next[to_del];
    lst->prev[lst->next[to_del]] = prev;
    lst->next[to_del] = -lst->free;
    lst->free = to_del;
    HtmlEnd (lst->logfile);
}    

void ListCheck (List* lst)
{
    if (lst == 0)
        assert(!"ERROR: LIST POINTER IS ZERO");
}

void ListResize (List* lst, size_t new_capacity)
{
    ListCheck (lst);
    lst->data = realloc (lst->data, new_capacity*sizeof(list_t));
    lst->next = realloc (lst->next, new_capacity*sizeof(long long));
    lst->prev = realloc (lst->prev, new_capacity*sizeof(long long));
    //===================insertes=to=the=free's=list==================
    for (long long i = (long long)lst->capacity; (size_t)i < new_capacity; i++)
    {
        lst->next[i] = -lst->free;
        lst->free = i;

        lst->prev[i] = -1;

        lst->data[i] = 0;
    }
    //=============================end=================================
    lst->capacity = new_capacity;
}

List* Linearization  (List* lst)
{
    ListCheck (lst);

    List* new_lst  = ListCtor (lst->capacity, "logs/new_log_for_linearization.html");
    long long phys_n = 0;
    long long last_pos = new_lst->fic;
    for (size_t i= 1; i <= lst->size; i++)
    {
        phys_n = VerySlowDoNotCallMeLogicalToPhysical (lst, i);
        last_pos = ListInsertAft (new_lst, last_pos, lst->data[phys_n]);
    }

    memcpy (lst->data, new_lst->data, new_lst->capacity * sizeof(list_t));
    memcpy (lst->next, new_lst->next, new_lst->capacity * sizeof(long long));
    memcpy (lst->prev, new_lst->prev, new_lst->capacity * sizeof(long long));
    lst->free = new_lst->free;
    lst->linearized = 1;

    ListDtor (new_lst);
    system ("rm logs/new_log_for_linearization.html");
    return lst;
}

long long VerySlowDoNotCallMeLogicalToPhysical (List* lst, size_t log_num)
{
    ListCheck (lst);
    long long cur = lst->fic;

    for (size_t i = 0; i < log_num; i++)
        cur = lst->next[cur];
    return cur;
}



void ListGraphDump (List* lst, char* name)
{
    ListCheck (lst);
    if (lst->size > 0)
    {
        system ("mkdir temp");
        FILE* dotfile = fopen ("temp/dump.dot", "w");

        char* pic_name = calloc (100, sizeof(char));
        memcpy (pic_name, "dot temp/dump.dot -T svg -o logs/", 35*sizeof(char));
        strcat (pic_name, name);

        DtStart (dotfile);
        DtSetTitle (dotfile, lst);
        long long cur = lst->next[lst->fic];
        while (cur != lst->fic)
        {
            DtSetNode (dotfile, lst, cur);
            cur = lst->next[cur];
        }
        fprintf (dotfile, "\n\n\n");

        DtSetDependence (dotfile, lst);
        DtEnd (dotfile);
        fclose(dotfile);


        system(pic_name);
        ImportPicture (lst->logfile, name);

        system ("rm -rf temp/");
        free (pic_name);
    }    
}

void ListDtor (List* lst)
{
    ListCheck (lst);
    HtmlEnd (lst->logfile);
    free (lst->data);
    free (lst->next);
    free (lst->prev);
    free (lst);
}
#include "Dump.h"
void DtStart (FILE* dotfile)
{
    fprintf (dotfile, "digraph G {\n");
    fprintf (dotfile, "rankdir = LR\n");
}

void DtSetTitle(FILE* dotfile, List* lst)
{
    fprintf (dotfile, "Data [shape=record, label =\"free = %d\\ncapacity = %d\\nsize = %d\\nhead = %d\\n tail = %d\\n\"]\n", lst->free, lst->capacity, lst->size, lst->head, lst->tail);
}

void DtSetNode (FILE* dotfile, List* lst, int i)
{
    fprintf (dotfile, "Node%d [shape=record, label=\"%d|data\\n%d|next\\n%d|prev\\n%d\"]\n", i, i, lst->data[i], lst->next[i], lst->prev[i]);
}

void DtSetDependence (FILE* dotfile, int size)
{
    for (int i = 1; i < size; i++)
        fprintf (dotfile, "Node%d -> ", i);
    fprintf (dotfile, "Node%d\n", size);
}

void DtEnd (FILE* dotfile)
{
    fprintf (dotfile, "}\n");
} 
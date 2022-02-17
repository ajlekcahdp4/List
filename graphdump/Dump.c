#include "Dump.h"
void DtStart (FILE* dotfile)
{
    fprintf (dotfile, "digraph G {\n");
    fprintf (dotfile, "rankdir = LR\n");
}

void DtSetTitle(FILE* dotfile, List* lst)
{
    fprintf (dotfile, "free [shape=record, style=rounded, label =\"free = %d\"];\n", lst->free);
    fprintf (dotfile, "capacity [shape=record, style=rounded, label =\"capacity = %d\"];\n", lst->capacity);
    fprintf (dotfile, "head [shape=record, style=rounded, label =\"head = %d\"];\n", lst->head);
    fprintf (dotfile, "tail [shape=record, style=rounded, label =\"tail = %d\"];\n\n\n", lst->tail);
}

void DtSetNode (FILE* dotfile, List* lst, int* i)
{
    if (*i <= lst->size)
    {
        fprintf (dotfile, "Node%d [shape=record, style=filled, fillcolor = \"palegreen\", label=\"<f0%d>%d|data\\n%d|<f1%d>next\\n%d|prev\\n%d\"]\n", *i, *i, *i, lst->data[*i], *i, lst->next[*i], lst->prev[*i]);
        *i = lst->next[*i];
    }
}

void DtSetDependence (FILE* dotfile, List* lst, int size)
{
    for (int i = 1; i != 0 && i != lst->tail;)
    {
        fprintf (dotfile, "Node%d: <f1%d> -> Node%d:<f0%d>[color=\"red\"];\n", i, i, lst->next[i], lst->next[i]);
        i = lst->next[i];
    }
}

void DtEnd (FILE* dotfile)
{
    fprintf (dotfile, "}\n");
} 
#include "DtDump.h"
void DtStart (FILE* dotfile)
{
    fprintf (dotfile, "digraph G {\n");
    fprintf (dotfile, "rankdir = LR\n");
}

void DtSetTitle(FILE* dotfile, List* lst)
{
    fprintf(dotfile ,"TITLE [shape=record, color=\"red\", label = \"DUMP of the list\"];\n\n");
    fprintf (dotfile, "free [shape=record, style=rounded, label =\"free | %d\"];\n", lst->free);
    fprintf (dotfile, "capacity [shape=record, style=rounded, label =\"capacity | %d\"];\n", lst->capacity);
    fprintf (dotfile, "head [shape=record, style=rounded, label =\"head | %d\"];\n", lst->next[lst->fic]);
    fprintf (dotfile, "tail [shape=record, style=rounded, label =\"tail | %d\"];\n", lst->prev[lst->fic]);
    fprintf (dotfile, "size [shape=record, style=rounded, label = \"size | %d\"];\n", lst->size);
    fprintf (dotfile, "linearized [shape=record, style=rounded, label = \"linearized|%d\"];\n\n\n", lst->linearized);
}

void DtSetNode (FILE* dotfile, List* lst, int i)
{
    fprintf (dotfile, "Node%d [shape=record, style=filled, fillcolor = \"palegreen\", label=\"<f0%d>%d|data\\n%d|<f1%d>next\\n%d|prev\\n%d\"]\n", i, i, i, lst->data[i], i, lst->next[i], lst->prev[i]);
}

void DtSetDependence (FILE* dotfile, List* lst)
{
    int i = lst->next[lst->fic];
    while (i != lst->prev[lst->fic])
    {
        fprintf (dotfile, "Node%d -> ", i);
        i = lst->next[i];
    }
    fprintf (dotfile, "Node%d [color=\"invis\"];\n\n", lst->prev[lst->fic]);
    
    i = lst->next[lst->fic];
    while (i != lst->prev[lst->fic])
    {
        fprintf (dotfile, "Node%d: <f1%d> -> Node%d:<f0%d>[color=\"red\"];\n", i, i, lst->next[i], lst->next[i]);
        i = lst->next[i];
    }

    fprintf(dotfile, "Node%d -> Node%d[color=\"invis\"];\n", lst->prev[lst->fic], lst->next[lst->fic]);
    fprintf(dotfile, "free -> capacity -> size -> head -> tail -> linearized [color=\"invis\"];\n");
}

void DtEnd (FILE* dotfile)
{
    fprintf (dotfile, "}\n");
} 

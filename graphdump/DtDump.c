#include "DtDump.h"
void DtStart (FILE* dotfile)
{
    fprintf (dotfile, "digraph G {\n");
    fprintf (dotfile, "rankdir = LR\n");
}

void DtSetTitle(FILE* dotfile, List* lst)
{
    fprintf(dotfile ,"TITLE [shape=record, color=\"red\", label = \"DUMP of the list\"];\n\n");
    fprintf (dotfile, "free [shape=record, style=rounded, label =\"free | %lld\"];\n", lst->free);
    fprintf (dotfile, "capacity [shape=record, style=rounded, label =\"capacity | %lu\"];\n", lst->capacity);
    fprintf (dotfile, "head [shape=record, style=rounded, label =\"head | %lld\"];\n", lst->next[lst->fic]);
    fprintf (dotfile, "tail [shape=record, style=rounded, label =\"tail | %lld\"];\n", lst->prev[lst->fic]);
    fprintf (dotfile, "size [shape=record, style=rounded, label = \"size | %lu\"];\n", lst->size);
    fprintf (dotfile, "linearized [shape=record, style=rounded, label = \"linearized|%d\"];\n\n\n", lst->linearized);
}

void DtSetNode (FILE* dotfile, List* lst, long long i)
{
    fprintf (dotfile, "Node%lld [shape=record, style=filled, fillcolor = \"palegreen\", label=\"<f0%lld>%lld|data\\n%d|<f1%lld>next\\n%lld|prev\\n%lld\"]\n", i, i, i, lst->data[i], i, lst->next[i], lst->prev[i]);
}

void DtSetDependence (FILE* dotfile, List* lst)
{
    long long i = lst->next[lst->fic];
    while (i != lst->prev[lst->fic])
    {
        fprintf (dotfile, "Node%lld -> ", i);
        i = lst->next[i];
    }
    fprintf (dotfile, "Node%lld [color=\"invis\"];\n\n", lst->prev[lst->fic]);
    
    i = lst->next[lst->fic];
    while (i != lst->prev[lst->fic])
    {
        fprintf (dotfile, "Node%lld: <f1%lld> -> Node%lld:<f0%lld>[color=\"red\"];\n", i, i, lst->next[i], lst->next[i]);
        i = lst->next[i];
    }

    fprintf(dotfile, "Node%lld -> Node%lld[color=\"invis\"];\n", lst->prev[lst->fic], lst->next[lst->fic]);
    fprintf(dotfile, "free -> capacity -> size -> head -> tail -> linearized [color=\"invis\"];\n");
}

void DtEnd (FILE* dotfile)
{
    fprintf (dotfile, "}\n");
} 

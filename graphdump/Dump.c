#include <stdio.h>
#include "Dump.h"

void DtStart (FILE* dotfile)
{
    fprintf (dotfile, "<graph>\n");
    fprintf (dotfile, "digraph G {\n");
}

void DtEnd (FILE* dotfile)
{
    fprintf (dotfile, "}\n");
    fprintf (dotfile, "</graph>");
} 
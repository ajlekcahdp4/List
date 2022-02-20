#include <stdio.h>
#include "../list.h"
void DtStart (FILE* dotfile);
void DtSetTitle(FILE* dotfile, List* lst);
void DtSetNode (FILE* dotfile, List* lst, int i);
void DtSetDependence (FILE* dotfile, List* lst);
void DtEnd (FILE* dotfile);

#include <stdio.h>
#include "dump.h"


FILE* HtmlStart (char* logname)
{
    FILE* logfile = fopen (logname, "w");
    fprintf (logfile, "<h1>Log File of the list</h1>\n");
    fprintf (logfile, "<pre>\n\n\n");
    return logfile;
}


void ImportPicture (FILE* logfile, char* PicName)
{
    fprintf (logfile, "<img src = \"%s\" width = \"1450px\">\n\n", PicName);
}
void PrintError (FILE* logfile, int Err)
{
    switch (Err)
    {
        case ERR_LIST_ZERO_POINTER:
            fprintf (logfile, "ERROR: list pointer in function is zero\n");
            break;
        case ERR_LIST_UNDERFLOW:
            fprintf (logfile, "ERROR: list underflow\n");
            break;
        default:;
    }
}

void HtmlEnd (FILE* logfile)
{
    fprintf (logfile, "</pre>\n");
    fclose (logfile);
}
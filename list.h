#ifndef LIST_INCLUDED
#define LIST_INCLUDED
typedef int list_t;

typedef struct List {
    list_t* data;
    FILE* logfile;
    int* next;
    int* prev;
    int  fic;
    int  free;
    int  capacity;
    int  size;
    int  linearized;
} List;

List*  ListCtor     (int capacity);
int  ListInsertAft  (List* lst, int last, list_t val);
int  ListDelete     (List* lst, int to_del);
int  ListGraphDump       (List* lst, char* pic_name);
int  ListDtor       (List* lst);
void ListHtmlDump (List* lst);
void ListResize     (List* lst, int new_capacity);
void ListCheck (List* lst);
List* Linearization  (List* lst);

int  VerySlowDoNotCallMeLogicalToPhysical (List* lst, int log_num);
#endif
#ifndef LIST_INCLUDED
#define LIST_INCLUDED
typedef int list_t;

typedef struct List {
    list_t* data;
    FILE* logfile;
    size_t  capacity;
    size_t size;
    long long int* next;
    long long int* prev;
    long long int  fic;
    long long int  free;
    int  linearized;
} List;

List*  ListCtor      (size_t capacity, char* logfile_name);
long long  ListInsertAft   (List* lst, long long int last, list_t val);
void  ListDelete     (List* lst, long long int to_del);
void  ListGraphDump  (List* lst, char* pic_name);
void  ListDtor       (List* lst);
void ListResize      (List* lst, size_t new_capacity);
List* Linearization  (List* lst);

long long  VerySlowDoNotCallMeLogicalToPhysical (List* lst, size_t log_num);
#endif
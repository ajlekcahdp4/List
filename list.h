#ifndef LIST_INCLUDED
#define LIST_INCLUDED
typedef int list_t;

typedef struct List {
    list_t* data;
    int* next;
    int* prev;
    int head;
    int tail;
    int free;
    int capacity;
    int size;
} List;

int ListCtor (List* lst);
int ListInsert (List* lst, int last, list_t val);
int ListDelete (List* lst, int to_del);
int ListDump (List* lst);
int ListDtor (List* lst);

void ListResize (List* lst, int new_capacity);
#endif
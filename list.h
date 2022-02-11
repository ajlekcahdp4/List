typedef int list_t;

typedef struct List {
    list_t* data;
    int* next;
    int* prev;
    int head;
    int tail;
    int free;
    int capacity;
} List;

int ListCtor (List* lst);
int ListInsert (List* lst, int last, list_t val);
int ListDtor (List* lst);
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
    FILE* logfile;
} List;

int ListCtor (List* lst, char* log_file_name);
int ListInsert (List* lst, int last, list_t val);
int ListDelete (List* lst, int to_del);
int ListDump (List* lst);
int ListDtor (List* lst);
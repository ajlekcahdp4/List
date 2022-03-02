# List
The Repository with my realization of list data structure

Table of contents:

[Usage](#Usage)

[dependancies](#Dependencies)

[example of usage](#Example-of-usage)

[functions](#functions)

[Insertion priciple](#insertion-principle)

[example of the dump](#example-of-graphic-dump-of-the-list)



## Features of this list:
* This is not an ordinary list implemented on pointers (where every node is a structure with data and poiners to the next and the previous nodes).
* There is a structure with 3 arrays (data, next and previous) in this list and all the nodes of the list contained in this arrays. This approach makes inserting a new element into the list much faster (O(1) against O(N)) than in its classical implementation. Because we don't need to allocated memory every time we want to insert the new element into the list(For more information about the insertion principle, see below).
* But the time saved on insertion, we spend on a longer resizing and initialization of the list (We need to alocate whole buffer for the list).

# Usage:
## To clone this repository run:
```bash
$ git clone https://github.com/ajlekcahdp4/List
```
## For using my list you need to compile:
```bash
C_COMPILER_NAME your_prog.c List/list.c List/dump/dump.c List/graphdump/DtDump.c
```
* You also can use my main.c file and then run:
```bash
make
```

# Dependencies
* To use graphic dump you need [graphviz](https://graphviz.org/download/)
* You can install graphviz by:
```bash
sudo apt install graphviz
```


## Example of usage:
```c
#include <stdio.h>
#include "list.h" // including the list


int main ()
{
    List* lst = 0;
    lst = ListCtor (8, "logs/log.html"); // Create a list structure

    int last_elem = ListInsertAft(lst, lst->fic, 1); // Insert first node and save it's index returns
    
    for (int i = 2; i < 10; i++)
        last_elem = ListInsertAft(lst, last_elem, i); // Insert several nodes in a loop

    ListGraphDump (lst, "dump1.svg"); // Dump our list

    lst = Linearization (lst); // There we understand, that we don't need speed any more and linearixed our list for most useful usege
    ListInsertAft(lst, 6, 10); // Insert node with data 10 after 6's node

    ListGraphDump (lst, "dump2.svg"); // One more dump
    ListDtor(lst); // Destructing our list
    return 0;
}
```
# Functions
## My list is a structure:
```c
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
```
* fic - index of fictitious element of the list (My list is not obvious looped) and this element is not useable.
* So, you can use `list->next[list->fic]` as an index of first list element and `list->prev[lst->fic]` as an index of last list element. 
My list has an ordinary list of functions:
## List constructor:
```c
List*  ListCtor (int capacity, char* logfile_name);
```
This function function you must call at the start of using list.
It will set all the list variables, open logfile and allocate buffer.
* Returns the pointer into the top of the list created.
* logfile must be .html document
## Insert node after element:
```c
int  ListInsertAft  (List* lst, int last, list_t val);
```
This function insert new node with value "val" in the list "lst" right after "last" element.
**The insertion takes place by a physical number of "last" element, not logical**
* This function return the physical number of the node insert. It can be usefull.
## Delete node:
```c
void  ListDelete (List* lst, int to_del);
```
This function delete node with **physical** number "to_del".
## List dump:
```c
void  ListGraphDump (List* lst, char* pic_name);
```
This function fills logfile with the dump of the list.
* You can call this function several times and then in logfile will be several dumps.
## List resize:
```c
void ListResize (List* lst, int new_capacity);
```
This function resizes list for a "new_capacity" parameter.
## Linearization of the list:
```c
List* Linearization  (List* lst);
```
This function reassemble the list so that the logical numbers match the physical ones. Returns the poiner on the top of linearized list.
* Use this function only if you don't need fast of the program, because this function is slow (O(N) + reallocation).
## List destructor:
```c
void  ListDtor (List* lst);
```
This function destroy your list, free all the memory allocated for list, close logfile e.t.c. 
# Insertion principle:
* The feature, that makes insertion much faster in our list is a variable "free", that always contains index of free element of the array. And this variable updates instantly, because we have the list of free elements of our array (In resizing of the list and deleting the nodes we must add elemnts in this lists of free).

# Example of graphic dump of the list:
<p align="center">
<img src="https://github.com/ajlekcahdp4/List/blob/main/examples/example_of_graph_dump.png">
</p>
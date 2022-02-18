# List
The Repository with my realization of list data structure
## Features of this list:
* This is not an ordinary list implemented on pointers (where every node is a structure with data and poiners to the next and the previous nodes).
* There is a structure with 3 arrays (data, next and previous) in this list and all the nodes of the list contained in this arrays. This approach makes inserting a new element into the list much faster (O(1) against O(N)) than in its classical implementation. Because we don't need to allocated memory every time we want to insert the new element into the list(For more information about the insertion principle, see below).
* But the time saved on insertion, we spend on a longer resizing and initialization of the list (We need to alocate whole buffer for the list).
# Functions supported:
My list has an ordinary list of functions:



## Insertion principle:
* The feature, that makes insertion much faster in our list is a variable "free", that always contains index of free element of the array. And this variable updates instantly, because we have the list of free elements of our array (In resizing of the list and deleting the nodes we must add elemnts in this lists of free).
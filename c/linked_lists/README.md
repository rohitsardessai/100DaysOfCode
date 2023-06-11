# Linked Lists

A linked list is a data structure that can store data like an array but provides a lot more dynamism. Unlike an array, a  linked list does not need a continuous chunk of memory. Instead, data is stored in nodes that can be places anywhere in memory and each node points to the location of the next. That way you can start from the beginning of teh list and traverse it all the way to the end.

## Advantages

* Dynamic: Unlike vectors, linked lists can grow and shrink as required without needing to reallocate memory.
* Efficient insertion: Elements can be inserted at the beginning of the list in constant time O(1).

## Drawbacks
* Memory: Linked lists can require more memory than arrays as each node needs to hold the value at that node as well as a pointer to the next node.
* Random access: Linked lists do not allow random access. In order to get the element at the nth position, you have to start at the beginning of the array and traverse it till the nth node.

 
## Implementation

A vector can be implemented using a struct that keeps track of:
* `data` - Value of the element in that node
* `next` - Pointer to the next node
```
typedef struct node {
    int data;
    struct node *next;
} node_t;
```
`node_t *new_node()` Creates a new node that points to NULL.

Look at the header file for function details.
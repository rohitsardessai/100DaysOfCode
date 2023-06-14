# Circular Doubly Linked Lists

A doubly linked list is a linked list with two pointers. Each node in a linked list has the value at that node, a pointer to the next node and a pointer to the previous node.

A circular doubly linked list, the last node points back to the first node and the first node points back to the previous node. This way a loop is created. You can traverse the linked list in both directions.
 
## Implementation

To implement a doubly linked list we can use this struct:
```
typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;
```
`value` - Value at that node
`*next` - Pointer to the next node
`*prev` - Pointer to the previous node

A new circular doubly linked list can be created by calling:</br>
`node_t *list_init(int value)`

Ex: 
```
node_t *head = list_init(2);
```

This initializes the head and sets the value to 2. The `*next` and `*prev` pointers are both set to point to head.

Look at the header file for the full list of functions and their details.
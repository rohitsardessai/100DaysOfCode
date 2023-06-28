# Queues

## Description

A queue is a linear data structure that is said to be open at both ends. Elements can be added and removed from the queue in a FIFO (first in first out manner).<br>
Queues are used in scheduling algorithms, such as job scheduling in operating systems. They can also be used in network traffic management.

## Implementation

A queue can be implemented using arrays with a struct like this:
```
typedef struct {
    int *data;
    int size;
    int write_index;
    int read_index;
} queue_t;
```

| Member        | Description                                   |
| ------------- | --------------------------------------------- |
| `*data`       | Pointer to the array that holds the data      |
| `size`        | Size of the array                             |
| `write_index` | Index where the next element will be added    |
| `read_index`  | Index of the least recently added element     |
<br>

`write_index` and `read_index` are the two points in the array that make the implementation work. They can also be called `push` and `pop` indices.

`write_index` Keeps track of the index where the next element can be stored. When a new element is added to the queue the write index is incremented.<br>
`read_index` Keeps track of the least recently added element. This is the element that `dequeue()` returns. When an element is read the `read_index` is incremented.

The queue can be thought of a circular buffer where elements are being added from one side and removed from the other. If the read or write index reaches the max length of the array, it can simply loop back around to the start if those elements have already been read (by a call to `dequeue()`).

If both the write index and read index are the same, that means the queue is empty. When the queue is full, the read index is one position behind the write index. There must always be one position before the read index that is kept empty because if a write operation happens at that index, the write index would have to be incremented and the read and write indices would be the same. This is indistinguishable from an empty queue.




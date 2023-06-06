# Dynamic arrays and vectors

## Vectors in c++

A vector is a data structure in c++ which is essentially an array that can change it's size at runtime. Typically the length of an array is specified during declaration and is fixed. Once an array is full, the you cannot just add more elements to it. Vectors can grow dynamically to accommodate more data.

## Dynamic arrays

A dynamic array is similar to a vector. Typically, dynamic arrays are meant to function exactly like regular arrays with the exception that they can change size.

Accessing elements of a dynamic array is similar to regular arrays using `arr[index]`.

 
## Implementation

A vector can be implemented using a struct that keeps track of:
* `size` - Number of elements currently in the array
* `capacity` - Total number of elements that the array can accommodate
* `data` - Pointer to the array
```
typedef struct {
    int size;
    int capacity;
    int *data;
} vector_t;
```
To create a new vector, the `new_vector(int capacity)` function is called. It creates the `vector_t` struct and returns a pointer to it.

Elements can then be added to the array. If the size of the array reaches it's capacity, the capacity is doubled.
This is done by allocating a new chunk of memory and copying the existing array to the new location.

| Function          | Description (See header file for detailed description)                   | Runtime                 |
| ----------------- | ------------------------------------------------------------------------ | ----------------------- |
| `new_vector`      | Creates a new vector                                                     | O(1)                    |
| `vector_insert`   | Inserts element at index and shift all following elements                | O(n)                    |
| `vector_at`       | Returns the element at the given index                                   | O(1)                    |
| `vector_destroy`  | Deletes vector                                                           | O(1)                    |
| `vector_capacity` | Returns the capacity of the vector                                       | O(1)                    |
| `vector_push`     | Append a value at the end of the array                                   | O(1), O(n) if resized   |
| `vector_size`     | Returns the number of elements in the array                              | O(1)                    |
| `vector_is_empty` | Returns true if the array is empty                                       | O(1)                    |
| `vector_pop`      | Returns and deletes the last element in the array                        | O(1), O(n) if resized   |
| `vector_delete`   | Deletes the element at the given index and shifts all following elements | O(n)                    |
| `vector_remove`   | Removes all occurrences of the specified value from the array.           | O(n)                    |
| `vector_find`     | Searches for a value and returns its index                               | O(n)                    |

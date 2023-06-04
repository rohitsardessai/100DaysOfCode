#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
/**
 * @brief Data structure to hold dynamic array. Capacity is the number of elements that the array can hold.
 *         Size is the number of elements currently in the array. *data is a pointer to the array
 *
 */
typedef struct {
    int size;
    int capacity;
    int *data;
} vector_t;

/**
 * @brief Creates a new dynamic array.
 *
 * @param capacity The number of elements that the array should hold.
 * @return Returns a pointer to the vector data structure tha holds the dynamic array.
 */
vector_t *new_vector(int capacity);

/**
 * @brief Inserts an element at a particular index in the array by moving all the elements from that index onwards by 1 position.
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 * @param index The index at which the value must be added.
 * @param value The value to be added.
 * @return Returns -1 if an error occurs and 0 if successful.
 */
int vector_insert(vector_t *vector, int index, int value);

/**
 * @brief Returns the value of the element stored at a given index.
 *
 * @param vector Pointer to the vector or dynamic array data structure
 * @param index Index of the value to be returned.
 * @return Returns the value stored at the given index.
 */
int vector_at(vector_t *vector, int index);

/**
 * @brief Frees the memory used by the dynamic array by calling free().
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 */
void vector_destroy(vector_t *vector);

/**
 * @brief Returns the total capacity of the vector
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 * @return The capacity of the array
 */
int vector_capacity(vector_t *vector);

/**
 * @brief Appends a value at the end of the array.
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 * @param value The value to be inserted
 */
void vector_push(vector_t *vector, int value);

/**
 * @brief Checks if the size of the array needs to be increased and increases it accordingly.
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 * @param required_capacity The new required capacity of the array.
 */
void vector_resize_check(vector_t *vector, int required_capacity);

/**
 * @brief Returns the size of the array, i.e. the number of elements that exist in the array
 *
 * @param vector Pointer to the vector or dynamic array data structure.
 * @return The size of the array.
 */
int vector_size(vector_t *vector);

#endif
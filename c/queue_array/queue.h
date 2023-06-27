#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/**
 * @brief Data structure to hold the queue. *data is a pointer to the array, size is the size of the array
 *
 */
typedef struct {
    int *data;
    int size;
    int write_index;
    int read_index;
} queue_t;

/**
 * @brief Creates a new queue of the specificed size
 *
 * @param size Size of the queue
 * @return Returns a poiter to the new queue
 */
queue_t *queue_create(int size);

/**
 * @brief Dealocates the memory used by the queue
 *
 * @param queue Pointer to the queue
 */
void destroy_queue(queue_t *queue);

/**
 * @brief Adds an element to the queue
 *
 * @param queue Pointer to the queue
 * @param value Value to be inserted in the queue
 * @return Returns 0 if successful, -1 if unsuccessful
 */
int enqueue(queue_t *queue, int value);

/**
 * @brief Pops an element from the queue
 *
 * @param queue Pointer to the queue
 * @return Returns the least recent element added to teh queue
 */
int dequeue(queue_t *queue);

/**
 * @brief Checks if the queue is empty
 *
 * @param queue Pointer to the queue
 * @return Returns true if the queue is empty
 * @return Returns false if the queue is not empty
 */
bool empty(queue_t *queue);

/**
 * @brief Checks if the queue is full
 *
 * @param queue Pointer to the queue
 * @return Returns true if the queue is full
 * @return Returns false if the queue is not full
 */
bool full(queue_t *queue);

/**
 * @brief Retuens the number of free slots left in the queue
 *
 * @param queue Pointer to the queue
 * @return Returns the number of free slots left in the queue
 */
int available_len(queue_t *queue);

#endif
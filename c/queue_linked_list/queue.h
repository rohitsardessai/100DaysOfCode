#ifndef QUEUE_H
#define QUEUE_H

#include "../doubly_linked_lists/doubly_linked_lists.h"
#include <stdbool.h>

typedef struct {
    node_t *head; // Pointer to the head of a doubly linked list
} queue_t;

/**
 * @brief Creates a new queue structure and sets the *head pointer to NULL
 *
 * @return Returns a pointer to the newly created queue
 */
queue_t *queue_create();

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
 */
void enqueue(queue_t *queue, int value);

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

#endif
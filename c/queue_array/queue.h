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

queue_t *new_queue(int size);

void destroy_queue(queue_t *queue);

void enqueue(queue_t *queue, int value);

const int dequeue(queue_t *queue);

bool empty(queue_t *queue);

bool full(queue_t *queue);

#endif
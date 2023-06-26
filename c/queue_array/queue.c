#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t *new_queue(int queue_size)
{
    if (queue_size < 1) {
        return NULL;
    }

    queue_t *new_queue = malloc(sizeof(queue_t));
    if (new_queue == NULL) {
        printf("Failed to alocate memory");
        exit(EXIT_FAILURE);
    }
    new_queue->data = malloc(sizeof(int) * queue_size);
    if (new_queue->data == NULL) {
        printf("Failed to alocate memory");
        exit(EXIT_FAILURE);
    }
    new_queue->write_index = 0;
    new_queue->read_index = 0;
    new_queue->size = queue_size;

    return new_queue;
}

bool empty(queue_t *queue)
{
    return (queue->write_index == queue->read_index);
}

bool full(queue_t *queue)
{
    int no_of_elements = (queue->read_index - queue->write_index + queue->size) % queue->size;
    int available_len = queue->size - no_of_elements - 1;
    if (available_len > 0) {
        return false;
    }
    return true;
}

void destroy_queue(queue_t *queue)
{
    if (queue == NULL) {
        return;
    }
    free(queue->data);
    free(queue);
}
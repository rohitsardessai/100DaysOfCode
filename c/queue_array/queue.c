#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t *queue_create(int queue_size)
{
    if (queue_size < 1) {
        return NULL;
    }

    queue_t *new_queue = malloc(sizeof(queue_t));
    if (new_queue == NULL) {
        printf("Failed to alocate memory");
        exit(EXIT_FAILURE);
    }
    new_queue->data = malloc((sizeof(int) * queue_size) + 1); // 1 space is always left empty to determine if queue is full or empty
    if (new_queue->data == NULL) {
        printf("Failed to alocate memory");
        exit(EXIT_FAILURE);
    }
    new_queue->write_index = 0;
    new_queue->read_index = 0;
    new_queue->size = queue_size + 1;

    return new_queue;
}

int available_len(queue_t *queue)
{
    int no_of_elements = (queue->write_index - queue->read_index + queue->size) % queue->size;
    int _available_len = queue->size - no_of_elements - 1;
    return _available_len;
}

int enqueue(queue_t *queue, int value)
{
    if (full(queue)) {
        return -1;
    }
    queue->data[queue->write_index] = value;
    queue->write_index = (queue->write_index + 1) % queue->size;

    return 0;
}

int dequeue(queue_t *queue)
{
    if (empty(queue)) {
        exit(EXIT_FAILURE);
    }
    int value = queue->data[queue->read_index];
    queue->read_index = (queue->read_index + 1) % queue->size;

    return value;
}

bool empty(queue_t *queue)
{
    return (queue->write_index == queue->read_index);
}

bool full(queue_t *queue)
{
    int free_slots = available_len(queue);
    if (free_slots > 0) {
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
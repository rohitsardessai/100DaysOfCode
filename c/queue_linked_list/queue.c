#include "queue.h"

queue_t *queue_create()
{
    queue_t *new_queue = malloc(sizeof(queue_t));
    new_queue->head = NULL;
    return new_queue;
}

void enqueue(queue_t *queue, int value)
{
    if (queue->head == NULL) {
        queue->head = list_init(value);
    } else {
        list_push_front(&queue->head, value);
    }
}

int dequeue(queue_t *queue)
{
    return list_pop_back(&queue->head);
}

void destroy_queue(queue_t *queue)
{
    list_destroy(queue->head);
    free(queue);
}

bool empty(queue_t *queue)
{
    return (list_size(queue->head) == 0);
}
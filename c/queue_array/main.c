#include "queue.h"
#include <stdio.h>

int main()
{
    int queue_size;
    printf("\nWhat sized queue do you want?\n");
    scanf("%d", &queue_size);
    queue_t *test_queue = queue_create(queue_size);

    for (int i = 0; i < queue_size + 1; i++) {
        enqueue(test_queue, i);
    }

    for (int i = 0; i < queue_size; i++) {
        int value = dequeue(test_queue);

        printf("Dequeued value: %i\n", value);
    }

    destroy_queue(test_queue);
    printf("\nEND\n");
    return 0;
}
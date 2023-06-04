#include "vector.h"
#include <string.h>

vector_t *new_vector(int capacity)
{
    if (capacity < 1) {
        return NULL;
    }

    vector_t *vector = malloc(sizeof(vector_t));
    if (vector == NULL) {
        return NULL;
    }

    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(int) * capacity);

    if (vector->data == NULL) {
        return NULL;
    }
    return vector;
}

int vector_insert(vector_t *vector, int index, int value)
{
    if (index < 0 || index >= vector->size) {
        return -1;
    }

    vector_resize_check(vector, (vector->size + 1));

    memmove(&vector->data[index + 1], &vector->data[index], ((vector->size - index) * sizeof(int)));
    vector->data[index] = value;
    vector->size += 1;
    return 0;
}

int vector_at(vector_t *vector, int index)
{
    int value = vector->data[index];
    return value;
}

void vector_destroy(vector_t *vector)
{
    free(vector->data);
    free(vector);
}
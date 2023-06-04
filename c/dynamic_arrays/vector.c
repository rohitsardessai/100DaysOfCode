#include "vector.h"

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
    if (index < 0) {
        return -1;
    }
    if (index >= vector->capacity) {
        int new_capacity = vector->capacity * sizeof(int) * 2;
        vector->data = realloc(vector->data, new_capacity);
        vector->capacity = new_capacity;
    }
    vector->data[index] = value;
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
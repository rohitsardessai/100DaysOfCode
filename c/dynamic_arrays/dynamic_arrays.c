/**
 * @file dynamic_arrays.c
 * @author Rohit Sardessai
 * @brief Implement a simple dynamic array in c.
 * @version 0.1
 * @date 2023-06-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "vector.h"
#include <stdio.h>

int main()
{
    vector_t *arr = new_vector(5);
    for (int i = 0; i < 15; i++) {
        vector_push(arr, i);
        printf("%d\n", vector_at(arr, i));
    }
    vector_insert(arr, 5, 100);

    printf("\n\n");
    for (int i = 0; i < vector_size(arr); i++) {
        printf("%d\n", vector_at(arr, i));
    }
    printf("\n");

    printf("Searching for %d. Response: %d\n", 9, vector_find(arr, 9));
    printf("Searching for %d. Response: %d\n", 110, vector_find(arr, 110));

    printf("Vector size before deleting an element: %d\n", vector_size(arr));
    vector_delete(arr, 11);
    printf("Vector size after deleting an element: %d\n", vector_size(arr));

    vector_remove(arr, 6);

    printf("\n");
    for (int i = vector_size(arr); i > 0; i--) {
        printf("Value: %d, size: %d\n", vector_pop(arr), vector_size(arr));
    }

    vector_destroy(arr);

    return 0;
}
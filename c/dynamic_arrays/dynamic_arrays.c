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

    vector_destroy(arr);

    return 0;
}
/**
 * @file pairs_in_array.c
 * @author Rohit Sardessai
 * @brief Given an array of numbers, find the number of pairs of each number
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

void simple_method(int *arr, int arr_len);
void better_method(int *arr, int arr_len);

void main()
{
    int arr[] = {1, 2, 2, 4, 5, 8, 8, 8, 4, 5, 6, 9, 7, 8};

    int arr_len = sizeof(arr) / sizeof(arr[0]);

    better_method(arr, arr_len);
}

/**
 * @brief   The simple method to find the number of pairs of each element in an array.
 *          This method traverses the whole array twice to compare and count the number of instances of each element
 *
 * @param arr
 * @param arr_len
 */
void simple_method(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++) {
        int no_of_appearences = 0;
        for (int j = 0; j < arr_len; j++) {
            if (arr[i] == arr[j]) {
                if (j < i) {
                    goto here;
                }
                no_of_appearences++;
            }
        }
        printf("%i has %i pairs\n", arr[i], (no_of_appearences / 2));
    here:
    }
    printf("\n\n");
}

/**
 * @brief Counts the number of pairs in O(n) time but uses more space. Suitable if the max value in the array is small.
 * 
 * @param arr
 * @param arr_len 
 */
void better_method(int *arr, int arr_len)
{
    int max = arr[0];
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int *freq = calloc((max + 1), sizeof(int));

    for (int i = 0; i < arr_len; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= max; i++) {
        if (freq[i] > 1) {
            int pairs = freq[i] / 2;
            printf("%i has %i pairs\n", i, pairs);
        }
    }

    free(freq);
}
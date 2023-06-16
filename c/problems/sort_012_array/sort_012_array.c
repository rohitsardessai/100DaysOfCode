/**
 * @file sort_012_array.c
 * @author Rohit Sardessai
 * @brief Problem from Geeks for Geeks. Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
 * @version 0.1
 * @date 2023-06-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.
Example 2:

Input:
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
*/

#include <stdio.h>

int sort012(int *array, int n);
void print_array(int *arr, int arr_len);

int main()
{
    int arr[] = {0, 2, 2, 1, 0, 1, 2, 1, 0, 2, 1, 2, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 2, 0, 2, 0, 2, 1, 0, 2, 0, 0, 1, 2, 0};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    printf("\nOriginal array:\n");
    print_array(arr, arr_len);

    sort012(arr, arr_len);

    printf("Sorted array:\n");
    print_array(arr, arr_len);

    return 0;
}

int sort012(int *array, int n)
{
    int counts[3] = {0};

    for (int i = 0; i < n; i++) {
        counts[array[i]] += 1;
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < counts[i]; j++) {
            array[index] = i;
            index++;
        }
    }
}

void print_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
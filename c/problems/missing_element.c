/**
 * @file missing_element.c
 * @author Rohit Sardessai
 * @brief Problem from Geeks for Geeks
 * @version 0.1
 * @date 2023-06-14
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:

Input:
N = 10
A[] = {6,1,2,8,3,4,7,10,5}
Output: 9

Your Task :
You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 106
1 ≤ A[i] ≤ 106
*/

#include <stdio.h>

int missingNumber(int *array, int n);

#define arr_len 4

int main()
{
    int arr[arr_len] = {1, 5, 3, 4};
    printf("Missing number is: %i\n", missingNumber(&arr, (arr_len + 1)));
    return 0;
}

int missingNumber(int *array, int n)
{
    int arr_size = n - 1;
    int tmp_arr[n];
    for (int i = 0; i < arr_size; i++) {
        tmp_arr[array[i]] = array[i];
    }

    for (int i = 1; i <= n; i++) {
        if (tmp_arr[i] != i) {
            return i;
        }
    }
}
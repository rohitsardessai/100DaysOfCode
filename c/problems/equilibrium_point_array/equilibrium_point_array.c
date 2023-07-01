/**
 * @file equilibrium_point_array.c
 * @author Rohit Sardessai
 * @brief Find the equilibrium point of an array. Full problem given below.
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Retun the index of Equilibrium point. (1-based index)

Example 1:

Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation:
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).


Example 2:

Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.


Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
1 <= A[i] <= 108
*/

#include <stdio.h>

int equilibrium_point(long long a[], int n);

int main()
{
    long long arr[] = {1, 3, 5, 2, 2};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    printf("\nAnswer: %i\n", equilibrium_point(arr, arr_len));
}

int equilibrium_point(long long a[], int n)
{
    long long sum_left = 0;
    long long sum_right = 0;

    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (i == j) {
            if (sum_left == sum_right) {
                return (i + 1);
            } else {
                return -1;
            }
        }
        if (sum_left >= sum_right) {
            sum_right += a[j];
            j--;
        } else {
            sum_left += a[i];
            i++;
        }
    }

    return -1;
}
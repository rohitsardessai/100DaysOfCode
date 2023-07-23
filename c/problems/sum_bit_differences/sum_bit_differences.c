#include <stdint.h>
#include <stdio.h>

/*
From: geeksforgeeks.org
Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements.
Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.

For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Examples :

Input: arr[] = {1, 2}
Output: 4
All pairs in array are (1, 1), (1, 2)
                       (2, 1), (2, 2)
Sum of bit differences = 0 + 2 +
                         2 + 0
                      = 4

Input:  arr[] = {1, 3, 5}
Output: 8
All pairs in array are (1, 1), (1, 3), (1, 5)
                       (3, 1), (3, 3) (3, 5),
                       (5, 1), (5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0
                       = 8*/

int sum_bit_differences(int *arr, int arr_len)
{
    int sum = 0;
    for (int i = 0; i < 32; i++) {
        int set_bits = 0;
        for (int j = 0; j < arr_len; j++) {
            if ((arr[j] >> i) & 1) {
                set_bits++;
            }
        }
        int unset_bits = arr_len - set_bits;
        sum += (2 * set_bits * unset_bits);
    }
    return sum;
}

int main()
{
    int arr[] = {1, 3, 5, 9, 45, 26, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of bit differences: %d\n", sum_bit_differences(arr, n));
    return 0;
}
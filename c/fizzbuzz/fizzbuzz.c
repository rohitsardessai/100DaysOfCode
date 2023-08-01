/**
 * @file fizzbuzz.c
 * @author Rohit Sardessai
 * @brief A program to output the result of the game fizzbuzz.
 *  FizzBuzz is a common coding task given during interviews that tasks candidates
 *  to write a solution that prints integers one-to-N, labeling any integers divisible by three
 *  as “Fizz,” integers divisible by five as “Buzz” and integers divisible by both three and
 *  five as “FizzBuzz.” Understanding how to solve it can help reinforce good coding practices.
 * @version 0.1
 * @date 2023-06-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_fizzbuzz(int no_of_digits);
char *get_fizzbuzz_output_string(int no_of_elements, int *output_len);
char *better_fizzbuzz_output_string(int no_of_digits, int *output_len);

int main()
{
    int no_of_elements;
    printf("\r\nHow many elements would you like to print?\n");
    scanf("%i", &no_of_elements);
    // print_fizzbuzz(no_of_elements);

    char *output;
    int output_len;
    // output = get_fizzbuzz_output_string(no_of_elements, &output_len);
    output = better_fizzbuzz_output_string(no_of_elements, &output_len);

    int len = strlen(output);
    printf("\nlen: %i\n", len);

    printf("\nOutput: ");
    for (int i = 0; i < output_len; i++) {
        printf("%c", output[i]);
    }
    printf("\r\nEND\r\n");
    free(output);
    return 0;
}

/**
 * @brief Print the output of fizzbuzz
 *
 * @param no_of_digits The output will be printed from 1 to no_of_digits
 */
void print_fizzbuzz(int no_of_digits)
{
    printf("\r\nOutput:\n\n");
    for (int i = 1; i <= no_of_digits; i++) {
        if (i % 3 == 0) {
            if (i % 5 == 0) {
                printf("Fizzbuzz\n");
            } else {
                printf("Fizz\n");
            }
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%i\n", i);
        }
    }
    printf("\r\nEND\r\n");
}

/**
 * @brief Get the output of fizzbuzz as a null terminated array
 *
 * @param no_of_digits The output will be printed from 1 to no_of_digits
 * @param output_len Pointer to int holding th length of the output (without null character)
 * @return char* Pointer to the array wiich holds the output. The array will be null terminated
 */
char *get_fizzbuzz_output_string(int no_of_digits, int *output_len)
{
    char *output;
    output = malloc(sizeof(char) * 5 * no_of_digits);

    output[0] = '\0';

    for (int i = 1; i <= no_of_digits; i++) {
        if (i % 3 == 0) {
            if (i % 5 == 0) {
                strcat(output, "Fizzbuzz ");
            } else {
                strcat(output, "Fizz ");
            }
        } else if (i % 5 == 0) {
            strcat(output, "Buzz ");
        } else {
            char str[5];
            sprintf(str, "%d ", i);
            strcat(output, str);
        }
    }

    *output_len = strlen(output);

    return output;
}

char *better_fizzbuzz_output_string(int no_of_digits, int *output_len)
{
    char *output;
    output = malloc(sizeof(char) * 5 * no_of_digits);

    output[0] = '\0';

    for (int i = 1; i <= no_of_digits; i++) {
        char tmp[9] = "";
        if (i % 3 == 0) {
            strcat(tmp, "Fizz");
        }
        if (i % 5 == 0) {
            strcat(tmp, "Buzz");
        }
        if (strlen(tmp) == 0) {
            snprintf(tmp, sizeof(tmp), "%d", i);
        }
        strcat(output, tmp);
        strcat(output, " ");
    }

    *output_len = strlen(output);

    return output;
}
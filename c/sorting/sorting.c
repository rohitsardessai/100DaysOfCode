#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    int length;
} array_t;

array_t *create_random_array(int arr_len);
void bubble_sort(int *arr, int len);
void swap(int *a, int *b);
void destroy_array(array_t *arr);
void print_array(int *arr, int arr_len);
double sort_using(void (*algorithm)(int *, int), int *arr, int arr_len);

int main()
{
    array_t *arr = NULL;
    arr = create_random_array(50);

    printf("\nUn-sorted array:\n");
    print_array(arr->array, arr->length);
    printf("\n");

    double cpu_time_used = sort_using(bubble_sort, arr->array, arr->length);

    printf("\nSorted array:\n");
    print_array(arr->array, arr->length);
    printf("\n");

    printf("Execution time: %f seconds\n", cpu_time_used);

    destroy_array(arr);

    return 0;
}

/**
 * @brief Calls the specified sorting function with the given array and array length parameters
 *
 * @param algorithm Function pointer to the sorting function.
 *                  It is expected to take two arguments: an array pointer (int *) and the array length (int)
 * @param arr Pointer to the array to be sorted
 * @param arr_len The length of the array
 * @return Returns the time taken to execute the function
 */
double sort_using(void (*algorithm)(int *, int), int *arr, int arr_len)
{
    clock_t start, end;
    start = clock();

    algorithm(arr, arr_len);

    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        bool swapped = false;
        for (int j = 0; j < (len - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            if (swapped = false) {
                return;
            }
        }
    }
}

/**
 * @brief Create a random array_t object. The array consists of values in the range 0 - 2*arr_len,
 *
 * @param arr_len Length of the array to be created
 * @return Returns an array_t struct that holds a pointer to the array and the length of the array
 */
array_t *create_random_array(int arr_len)
{
    array_t *new_array = malloc(sizeof(array_t));
    new_array->array = malloc(sizeof(int) * arr_len);

    if (new_array == NULL || new_array->array == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    new_array->length = arr_len;

    int random_no_range = 2 * arr_len;
    for (int i = 0; i < arr_len; i++) {
        new_array->array[i] = rand() % random_no_range;
    }

    return new_array;
}

/**
 * @brief Frees the memory allocated for the array
 *
 * @param arr
 */
void destroy_array(array_t *arr)
{
    free(arr->array);
    free(arr);
}

void print_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
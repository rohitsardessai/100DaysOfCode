#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    int length;
} array_t;

array_t *create_random_array(int arr_len);
void destroy_array(array_t *arr);
void print_array(int *arr, int arr_len);
int search_using(int (*algorithm)(int *, int, int), int *arr, int arr_len, int no_to_find);
int linear_search(int *arr, int arr_len, int no_to_find);

int main()
{
    printf("Enter the size of the array\n");
    int arr_size;
    scanf("%d", &arr_size);
    if (arr_size < 1) {
        printf("Array size cannot be less than 1.\n");
        return 0;
    }

    array_t *arr = NULL;
    arr = create_random_array(arr_size);

    printf("\nArray:\n");
    print_array(arr->array, arr->length);
    printf("\n");

    printf("Enter value to find\n");
    int no_to_find;
    scanf("%d", &no_to_find);

    int index = search_using(linear_search, arr->array, arr->length, no_to_find);

    if (index < 0) {
        printf("The number does not exist in the array.\n");
    } else {
        printf("Found at index %i.\n", index);
    }
    printf("\n");

    return 0;
}

/**
 * @brief Perform linear search on the given array
 *
 * @param arr Pointer to the array
 * @param arr_len Length of the array
 * @param no_to_find The number to search for
 * @return Returns the index of the first occurrence of the number to be searched. Returns -1 if not found
 */
int linear_search(int *arr, int arr_len, int no_to_find)
{
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == no_to_find) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Calls the given function with the specified parameters
 *
 * @param algorithm Function pointer to the searching function.
 *                  It is expected to take two arguments: an array pointer (int *), the array length (int) and the number to find (int)
 * @param arr Pointer to the array to be sorted
 * @param arr_len The length of the array
 * @param no_to_find The number to search for
 * @return Returns the return value of the function called
 */
int search_using(int (*algorithm)(int *, int, int), int *arr, int arr_len, int no_to_find)
{
    clock_t start, end;
    start = clock();

    int index = algorithm(arr, arr_len, no_to_find);

    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n\n", cpu_time_used);
    return index;
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

    srand(time(NULL));

    new_array->length = arr_len;

    int random_no_range = (2 * arr_len) + 20;
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
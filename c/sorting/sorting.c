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
void merge_sort(int *arr, int arr_len);
void merge(int *main_arr, int *arr1, int arr1_len, int *arr2, int arr2_len);
void quick_sort(int *arr, int arr_len);
void _quick_sort(int *arr, int left_index, int right_index);
int partition(int *arr, int left_index, int right_index);

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

    printf("\nUn-sorted array:\n");
    print_array(arr->array, arr->length);
    printf("\n");

    // double cpu_time_used = sort_using(bubble_sort, arr->array, arr->length);
    double cpu_time_used = sort_using(quick_sort, arr->array, arr->length);

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

void merge_sort(int *arr, int arr_len)
{
    if (arr_len < 2) {
        return;
    }

    int pivot_point = arr_len / 2;

    int arr_left_len = pivot_point;
    int arr_right_len = arr_len - pivot_point;

    int arr_left[arr_left_len];
    int arr_right[arr_right_len];

    for (int i = 0; i < arr_left_len; i++) {
        arr_left[i] = arr[i];
    }

    for (int i = pivot_point; i < arr_len; i++) {
        arr_right[i - pivot_point] = arr[i];
    }

    merge_sort(arr_left, arr_left_len);
    merge_sort(arr_right, arr_right_len);

    merge(arr, arr_left, arr_left_len, arr_right, arr_right_len);
}

void merge(int *main_arr, int *left, int left_len, int *right, int right_len)
{
    int index_main = 0;
    int index_left = 0;
    int index_right = 0;

    while (index_left < left_len && index_right < right_len) {
        if (left[index_left] <= right[index_right]) {
            main_arr[index_main] = left[index_left];
            index_left++;
        } else {
            main_arr[index_main] = right[index_right];
            index_right++;
        }
        index_main++;
    }

    while (index_left < left_len) {
        main_arr[index_main] = left[index_left];
        index_left++;
        index_main++;
    }

    while (index_right < right_len) {
        main_arr[index_main] = right[index_right];
        index_right++;
        index_main++;
    }
}

int partition(int *arr, int left_index, int right_index)
{
    int pivot_point = arr[right_index];
    int index_of_smallest_element = left_index - 1;

    for (int i = left_index; i <= right_index - 1; i++) {
        if (arr[i] < pivot_point) {
            index_of_smallest_element++;
            swap(&arr[i], &arr[index_of_smallest_element]);
        }
    }
    swap(&arr[right_index], &arr[index_of_smallest_element + 1]);
    return index_of_smallest_element + 1;
}

void _quick_sort(int *arr, int left_index, int right_index)
{
    if (left_index < right_index) {
        int pivot_index = partition(arr, left_index, right_index);
        _quick_sort(arr, left_index, pivot_index - 1);
        _quick_sort(arr, pivot_index + 1, right_index);
    }
}

void quick_sort(int *arr, int arr_len)
{
    _quick_sort(arr, 0, arr_len - 1);
}
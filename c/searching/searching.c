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
void merge_sort(int *arr, int arr_len);
void merge(int *main_arr, int *arr1, int arr1_len, int *arr2, int arr2_len);
int binary_search(int *arr, int arr_len, int no_to_find);
int _binary_search(int *arr, int low, int high, int no_to_find);

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

    merge_sort(arr->array, arr->length);

    printf("\nArray:\n");
    print_array(arr->array, arr->length);
    printf("\n");

    printf("Enter value to find\n");
    int no_to_find;
    scanf("%d", &no_to_find);

    int index = search_using(binary_search, arr->array, arr->length, no_to_find);

    if (index < 0) {
        printf("The number does not exist in the array.\n");
    } else {
        printf("Found at index %i.\n", index);
    }
    printf("\n");

    destroy_array(arr);

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

/**
 * @brief Perform binary search
 *
 * @param arr Pointer to array
 * @param arr_len Length of the array
 * @param no_to_find The number to search for
 * @return Returns the index of the first occurrence of the number. Returns -1 if not found
 */
int binary_search(int *arr, int arr_len, int no_to_find)
{
    return _binary_search(arr, 0, (arr_len - 1), no_to_find);
}

int _binary_search(int *arr, int low, int high, int no_to_find)
{
    if (low > high) {
        return -1;
    }

    int mid_point = (low + high) / 2;

    if (arr[mid_point] == no_to_find) {
        return mid_point;
    }
    if (arr[mid_point] < no_to_find) {
        return _binary_search(arr, (mid_point + 1), high, no_to_find);
    } else {
        return _binary_search(arr, low, (mid_point - 1), no_to_find);
    }

    return -1;
}
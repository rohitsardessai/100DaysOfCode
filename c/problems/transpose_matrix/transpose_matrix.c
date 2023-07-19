#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int *matrix, int rows, int columns);
void transpose_matrix(int *matrix, int rows, int columns);

int main()
{
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    print_matrix(&matrix[0][0], 4, 3);
    transpose_matrix(&matrix[0][0], 4, 3);
    print_matrix(&matrix[0][0], 3, 4);

    return 0;
}

void transpose_matrix(int *matrix, int rows, int columns)
{
    int *tmp_matrix = malloc(rows * columns * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp_matrix[(j * rows) + i] = matrix[(i * columns) + j];
        }
    }

    memcpy(matrix, tmp_matrix, (rows * columns * sizeof(int)));

    free(tmp_matrix);
}

void print_matrix(int *matrix, int rows, int columns)
{
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[(i * columns) + j]);
        }
        printf("\n");
    }
}
/**
 * @file sort_employees.c
 * @author Rohit Sardessai
 * @brief Read employee details from a csv file and sort based on particular fields
 * @version 0.1
 * @date 2023-06-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *city;
    char *department;
} employee_t;

int compare_str(const void *str1, const void *str2);
void sort_by_name(employee_t *employees, int employee_count);
void free_employee(employee_t *employee);

int main()
{
    FILE *file;
    file = fopen("employee_details.csv", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }

    employee_t employees[100];
    int employee_count = 0;

    char line_buffer[100];
    fgets(line_buffer, sizeof(line_buffer), file); // Read and discard the first heading line
    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        char *token;
        const char *delimiter = ",";

        token = strtok(line_buffer, delimiter); // Note that strtok() will modify the string passed into it.
        employees[employee_count].name = strdup(token);
        token = strtok(NULL, delimiter);
        employees[employee_count].age = atoi(token);
        token = strtok(NULL, delimiter);
        employees[employee_count].city = strdup(token);
        token = strtok(NULL, delimiter);
        employees[employee_count].department = strdup(token);

        employee_count++;
    }
    fclose(file);

    printf("There are %i employees.\n", employee_count);

    sort_by_name(employees, employee_count);

    printf("\nEmployees:\n");
    for (int i = 0; i < employee_count; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("City: %s\n", employees[i].city);
        printf("Department: %s\n", employees[i].department);
        printf("\n");
        free_employee(&employees[i]);
    }
    printf("\n");

    return 0;
}

int compare_str(const void *str1, const void *str2)
{
    return strcmp(*(const char **)str1, *(const char **)str2);
}

void sort_by_name(employee_t *employees, int employee_count)
{
    qsort(employees, employee_count, sizeof(employee_t), compare_str);
}

void free_employee(employee_t *employee)
{
    free(employee->name);
    free(employee->city);
    free(employee->department);
}
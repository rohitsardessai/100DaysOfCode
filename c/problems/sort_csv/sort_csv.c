/**
 * @file sort_csv.c
 * @author Rohit Sardessai
 * @brief Read a csv file that contains a list of names and sort them
 * @version 0.1
 * @date 2023-06-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_str(const void *str1, const void *str2);

int main()
{
    FILE *file;
    file = fopen("names.csv", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }

    char buffer[1000];

    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Failed to read file\n");
    }

    fclose(file);

    printf("\nFile:\n%s\n", buffer);

    int no_of_names = 0;
    char *names[100];
    char *token;
    const char *delimiter = ",";

    token = strtok(buffer, delimiter); // Note that strtok() will modify the string passed into it.
    while (token != NULL) {
        names[no_of_names] = strdup(token); // Note: strdup() allocates space but does not free it. The user needs to free the space

        no_of_names++;

        token = strtok(NULL, delimiter); // If str is a null pointer, the call is treated as a subsequent call to strtok: the function continues from where it left in previous invocation.
    }

    qsort(names, no_of_names, sizeof(names[0]), compare_str);

    printf("There are %i names.\n", no_of_names);
    printf("\nSorted names:\n");
    for (int i = 0; i < no_of_names; i++) {
        printf("%s ", names[i]);
        free(names[i]); // Free the memory allocated by strdup
    }
    printf("\n");

    return 0;
}

int compare_str(const void *str1, const void *str2)
{
    return strcmp(*(const char **)str1, *(const char **)str2);
}
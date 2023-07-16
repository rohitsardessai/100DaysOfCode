#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverse_string(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

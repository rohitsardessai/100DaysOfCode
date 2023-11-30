#include <dlfcn.h>
#include <stdio.h>

int main()
{
    // Load the shared library
    void *handle = dlopen("./libaddition.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // Get a pointer to the add function
    int (*add_function)(int, int) = dlsym(handle, "add");

    if (!add_function) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // Use the function
    int result = add_function(5, 7);
    printf("Result: %d\n", result);

    // Unload the shared library
    dlclose(handle);

    return 0;
}

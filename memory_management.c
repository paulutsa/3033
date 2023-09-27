#include <stdio.h>
#include <stdlib.h>

int main() {
    // Memory Leak: Allocating memory but forgetting to free it
    char *memory_leak = (char *)malloc(10);
    
    // Uninitialized Variable: Using a variable before giving it a value
    int uninitialized_variable;
    printf("Uninitialized Variable: %d\n", uninitialized_variable);
    
    // Invalid Memory Access: Trying to use memory that doesn't belong to us
    int array[5];
    array[6] = 42;

    // To fix the memory leak, we should free the allocated memory
    free(memory_leak);
    
    return 0;
}
